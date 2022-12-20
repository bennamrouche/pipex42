/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:37:33 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/18 17:43:19 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/lib.h"

typedef struct s_data
{
	pid_t	pid1;
	pid_t	pid2;
	int		p[2];
	int		in_fd;
	int		out_fd;
	char	*paths;
	char	**list_paths;
	char	**list_args;
	char	*cmd;
}	t_data;
int		cmd1(t_data info, char **av, char **env);
int		cmd2(t_data info, char **av, char **env);
#endif
