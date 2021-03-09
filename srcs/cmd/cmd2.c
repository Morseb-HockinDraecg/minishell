/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:24:47 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:24:48 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_shell *sh, void *b)
{
	printf("Ft_unset : to code\n");
	return (SUCCESS);
	(void)sh;
	(void)b;
}

int	ft_env(t_shell *sh, void *b)
{
	char	*s;
	t_list	*env;
	size_t	list_len;

	env = sh->env;
	list_len = ft_lstsize(env);
	while (env)
	{
		s = env->content;
		write(1, s, ft_strlen(s));
		if (--list_len)
			write(1, "\n", 1);
		env = env->next;
	}
	return (SUCCESS);
	(void)b;
}

int	ft_exit(t_shell *sh, void *b)
{
	char	*str;

	str = sh->cmd.arg->content;
	write(1, "exit\n", 5);
	if (sh->cmd.arg->next)
		write(1, "exit: too many arguments\n", 25);
	else
		exit(0);
// voir condition de retout ..... exit 54 a =/= exit a 54 
	(void)b;
	return (SUCCESS);
}

int	ft_nomatch(t_shell *sh, void *a)
{
	char	*str;

	str = sh->cmd.arg->content;
	write(1, str, ft_strlen(str));
	write(1, " : command not found\n", 21);
	return (SUCCESS);
	(void)a;
}
