#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    int k;
(void)argc;
(void)argv;
k = 0;
while (env[++k])
printf("%s\n", env[k]);
    // printf("%d\n", ECHO);
    // printf("%d\n", CD);
    // printf("%d\n", PWD);
    // printf("%d\n", EXPORT);
    // k = 5;
    // k = tabii(PWD, 4, 5);
    printf("%d\n", k);
}