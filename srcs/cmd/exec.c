#include "minishell.h"

static void	ft_test(t_shell *sh)
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
		l = l->next;
	}
	ft_lstclear(&sh->output, free);
}

int	exec_cmd(t_shell *sh)
{
	int			value;
	int			(*tab[8])(t_shell *sh, void *b);
	t_cmd_line	*current_cmd;
	t_list		*cmd_list;

	cmd_list = sh->cmd;
	value = -2;
	tab[NO_MATCH] = ft_nomatch;
	tab[ECHO] = ft_echo;
	tab[CD] = ft_cd;
	tab[PWD] = ft_pwd;
	tab[EXPORT] = ft_export;
	tab[UNSET] = ft_unset;
	tab[ENV] = ft_env;
	tab[EXIT] = ft_exit;
	while (cmd_list)
	{
		current_cmd = cmd_list->content;
		value = (*tab[current_cmd->cmd])(sh, current_cmd);
		cmd_list = cmd_list->next;
	}
	ft_test(sh);
	if (value == FAIL)
		return (FAIL);
	return (value);
}
