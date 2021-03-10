#include "minishell.h"

void	del_fct(char **x)
{
	free(*x);
	*x = NULL;
}

void	free_shell(t_shell *sh)
{
	t_list	*cmd;
	t_list	*env;
	char	**split;

	ft_lstclear(&sh->output, free);
	env = sh->env;
	while (env)
	{
		split = env->content;
		free(split[0]);
		free(split[1]);
		free(split);
		env = env->next;
	}
	ft_lstclear(&env, free);
	(void)cmd;
}
