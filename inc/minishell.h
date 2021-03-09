/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:24:17 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:24:19 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_next_line.h"
# define _POSIX_SOURCE
# include <unistd.h>
# undef _POSIX_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_cmd_line
{
	int			cmd;
	int			option_echo;
	t_list		*arg;
}				t_cmd_line;

typedef struct	s_shell
{
	t_list		*env;
	t_cmd_line	cmd;
	t_list		*output;
}				t_shell;

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
int		ft_echo(t_shell *sh, void *b);
int		ft_cd(t_shell *sh, void *b);
int		ft_pwd(t_shell *sh, void *size);
int		ft_export(t_shell *sh, void *b);

/*
**  CMD2
*/

int		ft_unset(t_shell *sh, void *b);
int		ft_env(t_shell *sh, void *b);
int		ft_exit(t_shell *sh, void *b);
int		ft_nomatch(t_shell *sh, void *b);

// int		lst_cmd(int a, t_shell *sh, void *y);

/*
**	PARSING
*/
int		parse_term(t_shell *sh);
void	parse_args(t_shell *sh, char **buf);



// TO SORT
void	exit_malloc_fail(void);
void	init_sh(int argc, char **argv, char **env, t_shell *sh);
void	trim_ws(char **line);
void	del_fct(char **x);
int		exec_cmd(t_shell *sh);

#endif
