/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:42 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/11 16:15:20 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_err(char *err)
{
	write(2, ft_strjoin(err, "\n"), ft_strlen(err) + 1);
}
int ft_error(char *err)
{
	write(2, ft_strjoin(err,"\n"), ft_strlen(err) + 1);
	return (1);
}
