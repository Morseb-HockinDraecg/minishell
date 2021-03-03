#ifndef _STRUCURE_MINISHELL_H
# define _STRUCURE_MINISHELL_H

#include <stdio.h>

enum cmd
{
    ECHO,
    CD,
    PWD,
    EXPORT,
    UNSET,
    ENV,
    EXIT,
};

enum valeur
{
    NO_MATCH = -1,

};

int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int tabii(int a, int x, int y);

#endif