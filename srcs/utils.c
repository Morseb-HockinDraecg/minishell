
#include "minishell.h"

void	del_fct(char **x)
{
	free(*x);
	*x = NULL;
}