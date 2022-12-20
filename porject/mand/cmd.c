/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:14 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/18 17:48:35 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../lib/lib.h"

static void	ft_free(t_data *info)
{
	int	i;

	i = 0;
	if (info->list_args != NULL)
	{
		while (info->list_args[i])
		{
			free(info->list_args[i]);
			i ++;
		}
		free(info->list_args);
	}
	i = 0;
	if (info->list_paths != NULL)
	{
		while (info->list_paths[i])
		{
			free(info->list_paths[i]);
			i++;
		}
		free(info->list_paths);
		free(info->cmd);
	}
}

static char	*find_cmd_path(char **paths, char *cmd)
{
	char	*tmp;
	char	*final_path;

	if (ft_strchr(cmd, '/') != NULL)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		final_path = ft_strjoin(tmp, cmd);
		if (access(final_path, F_OK) == 0)
			return (final_path);
		free(final_path);
		paths++;
	}
	return (NULL);
}

int	cmd1(t_data info, char **av, char **env)
{
	int	fd;

	dup2(info.p[1], 1);
	close(info.p[0]);
	fd = dup2(info.in_fd, 0);
	if (fd < 0)
	{
		exit(2);
	}
	info.list_args = ft_split(av[2], ' ');
	info.cmd = find_cmd_path(info.list_paths, info.list_args[0]);
	if (info.cmd == NULL)
	{
		print_err(ER_CMD_NT, info.list_args[0]);
		ft_free(&info);
		exit(127);
	}
	return (execve(info.cmd, info.list_args, env));
}

int	cmd2(t_data info, char **av, char **env)
{
	dup2(info.p[0], 0);
	close(info.p[1]);
	dup2(info.out_fd, 1);
	info.list_args = ft_split(av[3], ' ');
	info.cmd = find_cmd_path(info.list_paths, info.list_args[0]);
	if (!info.cmd)
	{
		print_err(ER_CMD_NT, info.list_args[0]);
		ft_free(&info);
		exit(127);
	}
	return (execve(info.cmd, info.list_args, env));
}
