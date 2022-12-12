/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:32:14 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/12 18:38:17 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(data *info)
{
	if (info->list_args != NULL)
	free(info->list_args);
	if (info->list_paths != NULL)
	free(info->list_paths);
}

static char	*find_cmd_path(char **paths, char *cmd)
{
	char *tmp;
	char *final_path;

	while (*paths)
	{
		tmp = ft_strjoin(*paths,"/");
		final_path = ft_strjoin(tmp,cmd);
		if (access(final_path,F_OK) == 0)
			return final_path;
		free(final_path);
		paths++;
	}

	return NULL;
}


int  cmd1(data info,char **av,char **env)
{
	dup2(info.in_fd,0);
	close(info.p[0]);
	dup2(info.p[1],1);
	info.list_args = ft_split(av[2],' ');
	info.cmd = find_cmd_path(info.list_paths, info.list_args[0]);
	if (!info.cmd)
	{
		ft_free(&info);
		print_err(ft_strjoin(ER_CMD_NT,info.cmd));
		exit(1);
	}
		execve(info.cmd,info.list_args,env);
	return 0;
}

int cmd2(data info, char **av, char **env)
{
	dup2(info.p[0], 0);
	close(info.p[1]);
	dup2(info.out_fd, 1);
	info.list_args = ft_split(av[3], ' ');
	info.cmd = find_cmd_path(info.list_paths, *info.list_args);
	if (!info.cmd)
	{
		ft_free(&info);
		print_err(ft_strjoin(ER_CMD_NT, info.cmd));
		exit(1);
	}
	execve(info.cmd, info.list_args, env);
	return 0;
}
