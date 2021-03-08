#include "minishell.h"

void	exec_cmd(t_shell *sh)
{
	t_list	*l;
	char	*c;
	int		cmd;

	cmd = sh->cmd.cmd;
	l = sh->cmd.arg;
	if (cmd <= CMD_ARG_1_MAX)
		lst_cmd(cmd, sh->env, NULL);
	else
	{
		while (l)
		{
			c = l->content;
			lst_cmd(cmd, sh->env, c);
			l = l->next;
			write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	ft_lstclear(&sh->cmd.arg, del_fct);
}