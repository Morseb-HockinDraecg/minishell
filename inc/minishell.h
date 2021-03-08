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

# include "cmd_minishell.h"
# include "get_next_line.h"

typedef struct	s_cmd_line
{
	int			cmd;
	int			option_echo;
	t_list		*arg;
}				t_cmd_line;

typedef struct	s_shell
{
	t_list		*env;
	char		*prompt;
	t_cmd_line	cmd;
}				t_shell;

/*
**	PARSING
*/
int		parse_term(t_shell *sh);
void	parse_args(t_shell *sh, char **buf);



// TO SORT
void	exit_malloc_fail(void);
void	init_sh(int argc, char **argv, char **env, t_shell *sh);
void	trim_ws(char **line);
void	del_fct(void *x);
void	exec_cmd(t_shell *sh);

#endif
