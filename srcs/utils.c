
#include "minishell.h"


void	del_fct(void *x)
{
	free(x);
	x = NULL;
}