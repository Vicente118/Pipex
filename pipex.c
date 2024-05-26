/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:26:41 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/26 12:24:40 by vdarras          ###   ########.fr       */
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
	if (pipe(fd) == -1)  // Creation du pipe
		exit_error();
	pid = fork();   // Creation du process enfant
	if (pid == -1)
		exit_error();
	if (pid == 0)
		child(fd, argv, envp);   // Execution du programme enfant
	if (waitpid(pid, NULL, 0) == -1)  // Attends que le process enfant soit terminé
		exit_error();
	if (pid > 0)
		parent(fd, argv, envp); // Execution du programme parent
    return 0;
}
