/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:30:29 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/28 16:39:11 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void    exit_error(void)
{
    perror("Error ");
	exit(1);
}

void    exit_alloc(void)
{
    write(2, "Error memory allocation\n", 25);
    exit(1);
}

void	free_tab(char **array)
{
	int	i;

    i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}


char    *path(char *command, char **envp)
{
    char    **dir_command;
    char    *temp;
    char    *final_path;
    int     i;

    i = 0;
    while (ft_strncmp(envp[i], "PATH", 4) != 0)
        i++;
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
            return (free_tab(dir_command), final_path);
        free(final_path);
    }
    return (free_tab(dir_command), NULL);
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
        free_tab(command_array);
        write(2, "zsh: command not found: ", 25);
        write(2, command, ft_strlen(command));
        write(2, "\n", 1);
        exit(127);
    }
    if (execve(path_to_command, command_array, envp) == -1)
    {
        free(path_to_command);
        free_tab(command_array);
        exit_error();
    }
    free(path_to_command);
    free_tab(command_array);
}
