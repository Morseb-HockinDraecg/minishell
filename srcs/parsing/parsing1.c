/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:28:35 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:28:36 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	cmp_cmd(char *cmd)
{
	int				cmp;
	static ssize_t	cmp_size = 7;

	cmp = ft_strncmp(cmd, "echo", cmp_size);
	if (!cmp)
		return (ECHO);
	cmp = ft_strncmp(cmd, "cd", cmp_size);
	if (!cmp)
		return (CD);
	cmp = ft_strncmp(cmd, "pwd", cmp_size);
	if (!cmp)
		return (PWD);
	cmp = ft_strncmp(cmd, "export", cmp_size);
	if (!cmp)
		return (EXPORT);
	cmp = ft_strncmp(cmd, "unset", cmp_size);
	if (!cmp)
		return (UNSET);
	cmp = ft_strncmp(cmd, "env", cmp_size);
	if (!cmp)
		return (ENV);
	cmp = ft_strncmp(cmd, "exit", cmp_size);
	if (!cmp)
		return (EXIT);
	return (NO_MATCH);
}

static void	take_cmd(t_cmd_line *current_cmd, char **buf)
{
	int			i;
	char		*cmd;
	char		*ptr_cmd;

	i = 0;
	cmd = (char *)malloc(sizeof(char) * ft_strlen(*buf) + 1);
	ptr_cmd = cmd;
	if (!cmd)
	{
		current_cmd->cmd = FAIL;
		exit_malloc_fail();
		return ;
	}
	while (*(*buf) != ' ' && **buf)
	{
		cmd[i++] = ft_tolower(**buf);
		(*buf)++;
	}
	cmd[i] = 0;
	i = cmp_cmd(cmd);
	current_cmd->cmd = i;
	if (!current_cmd->cmd)
		parse_args(current_cmd, &ptr_cmd);
	del_fct(&cmd);
}

static int	sort_line(t_shell *sh, char *buf)
{
	size_t		buf_len_to_handle;
	t_cmd_line	*cmd_line;

	buf_len_to_handle = ft_strlen(buf);
	while (buf_len_to_handle)
	{
		cmd_line = (t_cmd_line *)malloc(sizeof(t_cmd_line));
		cmd_line->arg = NULL;
		trim_ws(&buf);
		take_cmd(cmd_line, &buf);
		trim_ws(&buf);
		parse_args(cmd_line, &buf);
		ft_lstadd_back(&sh->cmd, ft_lstnew(cmd_line));
		buf_len_to_handle = ft_strlen(buf);
	}
	return (SUCCESS);
}

int	parse_term(t_shell *sh)
{
	int		ret;
	int		eol;
	char	*buf;

	eol = 1;
	while (eol)
	{
		ret = get_next_line(0, &buf);
		if (ret < 0)
			return (FAIL);
		eol = sort_line(sh, buf);
		del_fct(&buf);
	}
	return (0);
}
