/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:38:39 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/11 18:10:11 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h> //##
char *getpath(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}
int main(int ac, char **av, char **env)
{
(void) env;
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
	printf("%s",info.paths);
	if (info.list_paths == NULL)
		return (ft_error("paths : null !"));
	while (*info.list_paths > 0)
	{
		printf("====> %s\n",*info.list_args);
		info.l++;
	}
}
