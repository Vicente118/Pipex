/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:26:41 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/26 00:26:30 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(2, "Error bad number of arguments.\n", 32);
		return (0);
	}
	if (pipe(fd) == -1)
		exit_error();
	pid = fork();
	if (pid == -1)
		exit_error();
	if (pid == 0)
		child(fd, argv, envp);
	if (waitpid(pid, NULL, 0) == -1)
		exit_error();
    return 0;
}
