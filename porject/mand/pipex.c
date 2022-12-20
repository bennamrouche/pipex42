/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:39 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/18 17:46:17 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*getpath(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

static void	ft_free(t_data *info)
{
	int	i;

	i = 0;
	while (info->list_paths[i])
	{
		free(info->list_paths[i]);
		i++;
	}
	free(info->list_paths);
}

static void	ft_close_pipe(t_data *info)
{
	close(info->p[0]);
	close(info->p[1]);
}

int	main(int ac, char **av, char **env)
{
	t_data	info;

	if (ac != 5)
		return (ft_error(ER_ARG));
	info.in_fd = open(av[1], O_RDONLY);
	if (info.in_fd < 0)
		print_err(ER_INFILE, av[1]);
	info.out_fd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info.out_fd < 0)
		print_err(ER_OUTFILE, av[ac - 1]);
	info.paths = getpath(env);
	info.list_paths = ft_split(info.paths, ':');
	if (pipe(info.p) == -1)
		print_err(ER_PIPE, NULL);
	info.pid1 = fork();
	if (info.pid1 == 0)
		return (cmd1(info, av, env));
	info.pid2 = fork();
	if (info.pid2 == 0)
		return (cmd2(info, av, env));
	ft_close_pipe(&info);
	waitpid(info.pid1, NULL, 0);
	waitpid(info.pid2, NULL, 0);
	ft_free(&info);
}
