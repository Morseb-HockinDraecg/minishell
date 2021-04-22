#include "minishell.h"

void	ft_bs(int sign)
{
	printf("^\\Quit: %d\n", sign);
}

void	ft_c(int sign)
{
	write(STDIN_FILENO, "^C\n", 3);
	(void)sign;
}
