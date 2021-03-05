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

#include "cmd_minishell.h"

int	ft_echo(void *a, void *b)
{
	printf("Ft_echo : to code\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}

int	ft_cd(void *a, void *b)
{
	printf("Ft_cd : to code, chdir\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}

int	ft_pwd(void *pwd, void *size)
{
	(void)size;
	getcwd(pwd, sizeof(pwd));
	printf("Ft_pwd : %s\n", pwd);
	if (!pwd)
		return (FAIL);
	return (SUCCESS);
}

int	ft_export(void *a, void *b)
{
	printf("Ft_export : to code\n");
	return (SUCCESS);
	(void)a;
	(void)b;
}
