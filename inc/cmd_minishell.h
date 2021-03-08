/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_minishell.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:24:12 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:24:14 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CMD_MINISHELL_H
# define _CMD_MINISHELL_H

# define _POSIX_SOURCE
# include <unistd.h>
# undef _POSIX_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

enum	e_cmd
{
	NO_MATCH,
	ENV,
	CD,
	PWD,
	EXIT,
	EXPORT,
	UNSET,
	ECHO,
};

enum	e_ccmd
{
	CMD_ARG_1_MAX=4,
};

enum	e_valeur
{
	FAIL = - 1,
	SUCCESS,
	READING,
};

/*
**  CMD1
*/
int		ft_echo(t_list *env, void *b);
int		ft_cd(t_list *env, void *b);
int		ft_pwd(t_list *pwd, void *size);
int		ft_export(t_list *env, void *b);

/*
**  CMD2
*/

int		ft_unset(t_list *env, void *b);
int		ft_env(t_list *env, void *b);
int		ft_exit(t_list *env, void *b);
int		ft_nomatch(t_list *env, void *b);

int		lst_cmd(int a, t_list *x, void *y);

#endif
