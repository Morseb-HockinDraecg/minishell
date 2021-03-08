/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:24:25 by smorel            #+#    #+#             */
/*   Updated: 2021/03/08 12:24:26 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		parse_arg(t_shell *sh, char **buf)
{
	char	*arg;
	int		i;

	arg = (char *)malloc(sizeof(char) * ft_strlen(*buf) + 1);
	if (!arg)
	{
		exit_malloc_fail();
		return ;
	}
	i = 0;
	while (**buf != ' ' && **buf)
	{
		arg[i++] = **buf;
		(*buf)++;
	}
	arg[i] = 0;
	ft_lstadd_back(&sh->cmd.arg, ft_lstnew(arg));
}

static void		parse_simple_quote(t_shell *sh, char **buf)
{
	char	*arg;
	int		i;

	(*buf)++;
	arg = (char *)malloc(sizeof(char) * ft_strlen(*buf) + 1);
	if (!arg)
	{
		exit_malloc_fail();
		return ;
	}
	i = 0;
	while (**buf != '\'' && **buf)
	{
		arg[i++] = **buf;
		(*buf)++;
	}
	arg[i] = 0;
	ft_lstadd_back(&sh->cmd.arg, ft_lstnew(arg));
}

static void		parse_double_quote(t_shell *sh, char **buf)
{
	char	*arg;
	int		i;

	(*buf)++;
	arg = (char *)malloc(sizeof(char) * ft_strlen(*buf) + 1);
	if (!arg)
	{
		exit_malloc_fail();
		return ;
	}
	i = 0;
	while (**buf != '\"' && **buf)
	{
		arg[i++] = **buf;
		(*buf)++;
	}
	arg[i] = 0;
	ft_lstadd_back(&sh->cmd.arg, ft_lstnew(arg));
}

void			parse_args(t_shell *sh, char **buf)
{
	while (**buf && *buf)
	{
		if (**buf == '\"')
			parse_double_quote(sh, buf);
		else if (**buf == '\'')
			parse_simple_quote(sh, buf);
		else
			parse_arg(sh, buf);
		trim_ws(buf);
	}
}
