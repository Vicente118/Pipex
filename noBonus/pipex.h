/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:25:46 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/28 17:08:16 by vdarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <time.h>
# include "../libft/libft.h"

char    *path(char *command, char **envp);
void    exec(char *command, char **envp);
void    child(int *fd, char **argv, char **envp);
void    parent(int *fd, char **argv, char **envp);
void	free_tab(char **array);
void    exit_error(void);

#endif