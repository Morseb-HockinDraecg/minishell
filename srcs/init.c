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
	sh->cmd = NULL;
}

static void	init_env(char **env, t_shell *sh)
{
	char	**env_id_and_value;
	int		i;

	i = 0;
	sh->env = NULL;
	while (env[i])
	{
		env_id_and_value = ft_split(env[i], '=');
		ft_lstadd_back(&sh->env, ft_lstnew(env_id_and_value));
		i++;
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
