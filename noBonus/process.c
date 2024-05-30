#include "pipex.h"

void    child(int *fd, char **argv, char **envp)
{
    int infile;

    close(fd[0]);
    infile = open(argv[1], O_RDONLY, 0777);
    if (infile == -1)
        exit_error();
    if (dup2(infile, STDIN_FILENO) == -1)
        exit_error();
    if (dup2(fd[1], STDOUT_FILENO) == -1)
        exit_error();
    close(fd[1]);
    close(infile);
    exec(argv[2], envp);
}

void    parent(int *fd, char **argv, char **envp)
{
    int outfile;

    close(fd[1]);
    outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
    if (outfile == -1)
        exit_error();
    if (dup2(outfile, STDOUT_FILENO) == -1)
        exit_error();
    if (dup2(fd[0], STDIN_FILENO) == -1)
        exit_error();
    close(fd[0]);
    close(outfile);
    exec(argv[3], envp);
}