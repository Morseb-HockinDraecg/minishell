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
# include "libft.h"

typedef struct	s_cmd_line
{
	int			cmd;
	int			option_echo;
	t_list		*arg;
}				t_cmd_line;

typedef struct	s_shell
{
	t_list	*env;
	char	*prompt;
	t_list	*t_cmd_line;
}				t_shell;

/*
**	PARSING
*/
int		parse_term(char *term_line);


// TO SORT
void	exit_malloc_fail(void);

#endif
