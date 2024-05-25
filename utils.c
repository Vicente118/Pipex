/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:30:29 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/26 00:08:00 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    exit_error(void)
{
    perror("Error");
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
    while (ft_strnstr(envp[i], "PATH", 4) == NULL)
        i++;
    dir_command = ft_split(envp[i] + 5, ':');
    i = 0;
    while(dir_command[i])
    {
        temp = ft_strjoin(dir_command[i], "/");
        final_path = ft_strjoin(temp, command);
        free(temp);
        if (access(final_path, F_OK) == 0)
            return (free_tab(dir_command), final_path);
        free(final_path);
        i++;
    }
    free_tab(dir_command);
    return (NULL);
}

void    exec(char *command, char **envp)
{
    char    **command_array;
    char    *path_to_command;
    int     i;

    i = -1;
    command_array= ft_split(command, ' ');
    path_to_command = path(command_array[0], envp);
    if (!path_to_command)
    {
        free_tab(command_array);
        exit_error();
    }
    if (execve(path_to_command, command_array, envp) == -1)
        exit_error();
    {
        free(path_to_command);
        free_tab(command_array);
        exit_error();
    }
    free(path_to_command);
    free_tab(command_array);
}