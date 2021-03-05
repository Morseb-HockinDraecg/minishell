/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:24:25 by smorel            #+#    #+#             */
/*   Updated: 2021/03/05 10:24:26 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(char **env, t_shell *sh)
{
	char	*env_var;
	int		i;

	i = 0;
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
	sh->env = NULL;
	init_env(env, sh);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*sh;

	sh = (t_shell *)malloc(sizeof(t_shell));
	init_sh(argc, argv, env, sh);
	return (0);
}
