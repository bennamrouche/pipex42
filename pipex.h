/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:37:33 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/12 17:47:34 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PIPEX__H
#define __PIPEX__H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "error.h"

typedef struct s_data
{
	pid_t pid1;
	pid_t pid2;
	int p[2];
	int in_fd;
	int out_fd;
	char *paths;
	char **list_paths;
	char **list_args;
	char *cmd;
} data;

int		cmd1(data info, char **av, char **env);
int		cmd2(data info, char **av, char **env);
#endif
