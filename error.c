/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:42 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/15 20:11:36 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_err(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	free(err);
}

int	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	return (1);
}
