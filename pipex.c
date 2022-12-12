/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:39 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/12 18:21:31 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> //##
static char *getpath(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}
static void ft_free(data *info)
{
	free(info->list_paths);
}
static void ft_close_pipe(data *info)
{
	close(info->p[0]);
	close(info->p[0]);
}
int main(int ac, char **av, char **env)
{
	data	info;

	if (ac != 5)
		return (ft_error(ER_ARG));
	info.p[0] = open(av[1], O_RDONLY);
	if (info.p[0] < 0)
		print_err(ft_strjoin(ER_INFILE, av[1]));
	info.p[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC,0644);
	if (info.p[1] < 0)
	 print_err(ft_strjoin(ER_OUTFILE, av[ac - 1]));
	info.paths = getpath(env);
	info.list_paths =  ft_split(info.paths,':');
	info.pid1 = fork();
	if (info.pid1 == 0)
		return (cmd1(info, av,env));
	info.pid2 = fork();
	if (info.pid2 == 0)
		return (cmd2(info, av, env));
	ft_close_pipe(&info);
	waitpid(info.pid1,NULL,0);
	waitpid(info.pid2,NULL,0);
	ft_free(&info);
}
