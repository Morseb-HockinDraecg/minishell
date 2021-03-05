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

enum	e_cmd
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

enum	e_valeur
{
	NO_MATCH = -1,
	SUCCESS,
	FAIL,
};

/*
**  CMD1
*/
int		ft_echo(void *a, void *b);
int		ft_cd(void *a, void *b);
int		ft_pwd(void *pwd, void *size);
int		ft_export(void *a, void *b);
int		ft_unset(void *a, void *b);

/*
**  CMD2
*/

int		ft_env(void *a, void *b);
int		ft_exit(void *a, void *b);

int		tabii(int a, void *x, void *y);

#endif
