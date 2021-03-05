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

int	ft_unset(void *a, void *b)
{
	printf("Ft_unset : to code\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}

int	ft_env(void *a, void *b)
{
	printf("Ft_env : to code\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}

int	ft_exit(void *a, void *b)
{
	exit(0);
	printf("Ft_exit : to code\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}

int	tabii(int a, void *x, void *y)
{
	int value;
	int (*tab[7])(void *a, void *b);

	value = -2;
	tab[ECHO] = ft_echo;
	tab[CD] = ft_cd;
	tab[PWD] = ft_pwd;
	tab[EXPORT] = ft_export;
	tab[UNSET] = ft_unset;
	tab[ENV] = ft_env;
	tab[EXIT] = ft_exit;
	if (a > 7)
		return (NO_MATCH);
	value = (*tab[a])(x, y);
	if (value == FAIL)
		return (FAIL);
	return (value);
}
