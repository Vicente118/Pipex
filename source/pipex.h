/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:25:46 by vdarras           #+#    #+#             */
/*   Updated: 2024/06/03 17:26:43 by vdarras          ###   ########.fr       */
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
void    first_process(int *pipe, char **argv, char **envp);
void    process_pipe(int i, int **pipe, char **argv, char **envp);
void    final_process(int *pipe, int argc, char **argv, char **envp);
void    close_unused_pipes(int i, int j, int argc, int **fd_pipe);
void	free_tab(int **array);
void    free_tab_char(char **array);
int     length_array(int **array);
int     length_array_char(char **array);
void    exit_error(void);
void    exit_alloc(void);
void    check_special_cases(char **command_array);

#endif


// cd command not found