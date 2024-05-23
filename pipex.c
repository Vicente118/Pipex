/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:26:41 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/23 18:18:08 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int pid;
	pid = 9;
	
	printf("Main process before fork PID : %d\n", getpid());

	pid = fork();
	printf("Main process after fork PID : %d\n", getpid());
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		printf("Hello, im the chid process. My pid is : %d and my child pid is : %d\n", getpid(), pid);
	}
	else
	{
		printf("Hello I'm the main process. My pid is : %d and my child pid is : %d\n", getpid(), pid);
	}
	return (0);
}