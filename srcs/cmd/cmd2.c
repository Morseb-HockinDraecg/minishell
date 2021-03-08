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

#include "cmd_minishell.h"

int	ft_unset(t_list *env, void *b)
{
	printf("Ft_unset : to code\n");
	return (SUCCESS);
	(void)env;
	(void)b;
}

int	ft_env(t_list *env, void *b)
{
	char	*s;
	size_t	list_len;

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

int	ft_exit(t_list *env, void *b)
{
	printf("exit\n");
	exit(0);
	return (SUCCESS);
	(void)env;
	(void)b;
}

int	ft_nomatch(t_list *env, void *str)
{
	printf("%s : command not found\n", str);
	return (SUCCESS);
	(void)env;
}

int	lst_cmd(int a, t_list *x, void *y)
{
	int	value;
	int (*tab[8])(t_list *env, void *b);
	value = -2;
	tab[NO_MATCH] = ft_nomatch;
	tab[ECHO] = ft_echo;
	tab[CD] = ft_cd;
	tab[PWD] = ft_pwd;
	tab[EXPORT] = ft_export;
	tab[UNSET] = ft_unset;
	tab[ENV] = ft_env;
	tab[EXIT] = ft_exit;
	value = (*tab[a])(x, y);
	if (value == FAIL)
		return (FAIL);
	return (value);
}
