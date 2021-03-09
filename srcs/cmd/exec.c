#include "minishell.h"

// void	exec_cmd(t_shell *sh)
// {
// 	t_list	*l;
// 	char	*c;
// 	int		cmd;

// 	cmd = sh->cmd.cmd;
// 	l = sh->cmd.arg;
// 	if (cmd < CMD_ARG_1_MAX)
// 		lst_cmd(cmd, sh, l->content);
// 	else if (cmd == CMD_ARG_1_MAX)
// 		lst_cmd(cmd, sh, l->content);
// 	else
// 	{
// 		while (l)
// 		{
// 			c = l->content;
// 			lst_cmd(cmd, sh, c);
// 			l = l->next;
// 			write(1, " ", 1);
// 		}
// 	}
// 	write(1, "\n", 1);
// 	ft_lstclear(&sh->cmd.arg, del_fct);
// }

static void ft_test(t_shell *sh)
{
	t_list	*l;
	char	*s;
	int		l_len;

	l = sh->output;
	l_len = ft_lstsize(l);
	while (l)
	{
		s = l->content;
		write(1, s, ft_strlen(s));
		if (--l_len)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		l = l->next;
	}
}


int	exec_cmd(t_shell *sh)
{
	int	value;
	int (*tab[8])(t_shell *sh, void *b);

	value = -2;
	tab[NO_MATCH] = ft_nomatch;
	tab[ECHO] = ft_echo;
	tab[CD] = ft_cd;
	tab[PWD] = ft_pwd;
	tab[EXPORT] = ft_export;
	tab[UNSET] = ft_unset;
	tab[ENV] = ft_env;
	tab[EXIT] = ft_exit;
	value = (*tab[sh->cmd.cmd])(sh, NULL);
	ft_lstclear(&sh->cmd.arg, free);
	ft_test(sh);
	if (value == FAIL)
		return (FAIL);
	return (value);
}