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

int	main(int argc, char **argv, char **env)
{
	t_shell	*sh;
	char	prompt[20];

	sh = (t_shell *)malloc(sizeof(t_shell));
	init_sh(argc, argv, env, sh);
	ft_strlcpy(prompt, "BASH de coin coin : ", 22);
	while (1)
	{
		write(2, prompt, ft_strlen(prompt));
		parse_term(sh);
		exec_cmd(sh);
	}
	return (0);
}
