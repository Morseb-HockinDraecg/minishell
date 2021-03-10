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
	char	**s;
	t_list	*env;
	size_t	list_len;

	env = sh->env;
	list_len = ft_lstsize(env);
	while (env)
	{
		s = env->content;
		write(1, s[0], ft_strlen(s[0]));
		write(1, "=", 1);
		write(1, s[1], ft_strlen(s[1]));
		if (list_len)
			write(1, "\n", 1);
		env = env->next;
	}
	return (SUCCESS);
	(void)b;
}

// voir condition de retout ..... exit 54 a =/= exit a 54 

int	ft_exit(t_shell *sh, void *cmd)
{
	char	*str;

	str = NULL;
	if (ft_lstsize(((t_cmd_line *)cmd)->arg))
		str = ((t_cmd_line *)cmd)->arg->content;
	write(1, "exit\n", 5);
	if (str && ((t_cmd_line *)cmd)->arg->next)
		write(1, "exit: too many arguments\n", 25);
	else
	{
		free_shell(sh);
		exit(0);
	}
	return (SUCCESS);
	(void)sh;
}

int	ft_nomatch(t_shell *sh, void *cmd)
{
	char	*str;

	str = ((t_cmd_line *)cmd)->arg->content;
	write(1, str, ft_strlen(str));
	write(1, " : command not found\n", 21);
	return (SUCCESS);
	(void)sh;
}
