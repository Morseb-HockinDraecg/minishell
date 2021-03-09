/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:25:08 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 12:25:09 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_cmd_line(t_shell *sh)
{
	sh->cmd.cmd = -1;
	sh->cmd.option_echo = 0;
	sh->cmd.arg = NULL;
}

static void	init_env(char **env, t_shell *sh)
{
	char	*env_var;
	int		i;

	i = 0;
	sh->env = NULL;
	while (env[++i])
	{
		env_var = (char *)malloc(sizeof(char *));
		if (!env_var)
			exit_malloc_fail();
		env_var = env[i];
		ft_lstadd_back(&sh->env, ft_lstnew(env_var));
	}
}

void	init_sh(int argc, char **argv, char **env, t_shell *sh)
{
	(void)argc;
	(void)argv;
	init_env(env, sh);
	init_cmd_line(sh);
	sh->output = NULL;
}
