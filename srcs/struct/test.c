#include "functions_minishell.h"

int sum(int a, int b)
{
    return (a + b);
}

int sub(int a, int b)
{
    return (a - b);
}

int mult(int a, int b)
{
    return (a * b);
}

int tabii(int a, int x, int y)
{
	int value;
	int (*tab[7])(int x, int y);

	value = -2;
	tab[ECHO] = sum;
	tab[CD] = sub;
	tab[PWD] = mult;
	tab[EXPORT] = mult;
	tab[UNSET] = mult;
	tab[ENV] = mult;
	tab[EXIT] = mult;
	if (a > 7)
		return (NO_MATCH);
	value = (*tab[a])(x, y);
	return (value);
}