/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:43:42 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/18 17:49:22 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_err(char *str1, char *str2)
{
	if (str1 != NULL)
		write(2, str1, ft_strlen(str1));
	if (str2 != NULL)
		write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
}

int	ft_error(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	return (1);
}
