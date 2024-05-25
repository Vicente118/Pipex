/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarras <vdarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:25:46 by vdarras           #+#    #+#             */
/*   Updated: 2024/05/25 23:59:24 by vdarras          ###   ########.fr       */
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
# include "libft/libft.h"

typedef struct s_command
{
    char    *infile;
    char    *outfile;
    char    *cmd1;
    char    *cmd2;
}           t_command;

char    *path(char *command, char **envp);
void    exec(char *command, char **envp);
void	free_tab(char **array);
void    exit_error(void);

#endif