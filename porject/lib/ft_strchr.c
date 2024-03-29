/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 09:40:51 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/16 16:12:59 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strchr(const char *s, int x)
{
	while (*s)
	{
		if (*s == (char)x)
			return ((char *)s);
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (0);
}
