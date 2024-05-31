#include "pipex_bonus.h"

void    process_pipe(int i, int **pipe, char **argv, char **envp)
{
    if (dup2(pipe[i][0], STDIN_FILENO) == -1)
        exit_error();
    if (dup2(pipe[i + 1][1], STDOUT_FILENO == -1))
        exit_error();
    close(pipe[i][0]);
    close(pipe[i + 1][1]);
    exec(argv[i + 2], envp);
}
