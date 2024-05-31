#include "pipex_bonus.h"

void    first_process(int *pipe, char **argv, char **envp)
{
    int infile;

    close(pipe[0]);
    infile = open(argv[1], O_RDONLY, 0777);
    if (infile == -1)
    {
        write(2, "zsh: no such file or directory: ", 33);
        write(2, argv[1], ft_strlen(argv[1]));
        write(2, "\n", 1);
	    exit(1);
    }
    if (dup2(infile, STDIN_FILENO) == -1)
        exit_error();
    if (dup2(pipe[1], STDOUT_FILENO) == -1)
        exit_error();
    close(pipe[1]);
    close(infile);
    exec(argv[2], envp);
}

void    final_process(int *pipe, int argc, char **argv, char **envp)
{
    int outfile;

    close(pipe[1]);
    outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
    if (outfile == -1)
        exit_error();
    if (dup2(outfile, STDOUT_FILENO) == -1)
        exit_error();
    if (dup2(pipe[0], STDIN_FILENO) == -1)
        exit_error();
    close(pipe[0]);
    close(outfile);
    exec(argv[argc - 2], envp);
}

char    *path(char *command, char **envp)
{
    char    **dir_command;
    char    *temp;
    char    *final_path;
    int     i;

    i = -1;
    while (ft_strncmp(envp[++i], "PATH", 4) != 0);
    dir_command = ft_split(*(envp + i) + 5, ':');
    if (!dir_command)
        exit_alloc();
    i = -1;
    while(dir_command[++i])
    {
        temp = ft_strjoin("/", command);
        if (!temp)
            exit_alloc();
        final_path = ft_strjoin(dir_command[i], temp);
        if(!final_path)
            exit_alloc();
        free(temp);
        if (access(final_path, F_OK) == 0)
            return (free_tab_char(dir_command), final_path);
        free(final_path);
    }
    return (free_tab_char(dir_command), NULL);
}

void    exec(char *command, char **envp)
{
    char    **command_array;
    char    *path_to_command;

    command_array= ft_split(command, ' ');
    if (!command_array)
        exit_alloc();
    if (access(command, F_OK) != 0)
        path_to_command = path(command_array[0], envp);
    else
        path_to_command = command;
    if (!path_to_command)
    {
        write(2, "zsh: command not found: ", 25);
        write(2, command_array[0], ft_strlen(command_array[0]));
        write(2, "\n", 1);
        free_tab_char(command_array);
        exit(127);
    }
    if (execve(path_to_command, command_array, envp) == -1)
    {
        free(path_to_command);
        free_tab_char(command_array);
        exit_error();
    }
    free(path_to_command);
    free_tab_char(command_array);
}
