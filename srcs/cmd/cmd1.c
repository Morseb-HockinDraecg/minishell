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

int	ft_echo(t_list *env, void *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (SUCCESS);
	(void)env;
}

int	ft_cd(t_list *env, void *b)
{
	printf("Ft_cd : to code, chdir\n");
	return (SUCCESS);
	(void)env;
	(void)b;
}

int	ft_pwd(t_list *env, void *pwd)
{
	(void)env;
	getcwd(pwd, sizeof(pwd));
	printf("Ft_pwd : %s\n", pwd);
	if (!pwd)
		return (FAIL);
	return (SUCCESS);
}

int	ft_export(t_list *env, void *b)
{
	printf("Ft_export : to code\n");
	return (SUCCESS);
	(void)env;
	(void)b;
}
