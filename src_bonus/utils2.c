#include "pipex_bonus.h"

void    exit_alloc(void)
{
    write(2, "Error memory allocation\n", 25);
    exit(1);
}

void    close_unused_pipes(int i, int j, int argc, int **fd_pipe)
{
    while (++j < argc - 3)
    {
        if (i != j)
            close(fd_pipe[j][0]);
        if (i + 1 != j)
            close(fd_pipe[j][1]);
    }
}