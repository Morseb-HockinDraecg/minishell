/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:24:40 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:24:41 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_shell *sh, void *cmd)
{
	t_list	*l;
	char	*str;
	char	*output;
	size_t	len;

	l = ((t_cmd_line *)cmd)->arg;
	while (l)
	{
		str = l->content;
		len = ft_strlen(str);
		output = (char *)malloc(len + 1);
		ft_strlcpy(output, str, len + 1);
		ft_lstadd_back(&sh->output, ft_lstnew(output));
		l = l->next;
	}
	return (SUCCESS);
}

int	ft_cd(t_shell *sh, void *b)
{
	printf("Ft_cd : to code, chdir\n");
	return (SUCCESS);
	(void)sh;
	(void)b;
}

int	ft_pwd(t_shell *sh, void *pwd)
{
	(void)sh;
	getcwd(pwd, sizeof(pwd));
	printf("Ft_pwd : %s\n", pwd);
	if (!pwd)
		return (FAIL);
	return (SUCCESS);
}

int	ft_export(t_shell *sh, void *b)
{
	printf("Ft_export : to code\n");
	return (SUCCESS);
	(void)sh;
	(void)b;
}
