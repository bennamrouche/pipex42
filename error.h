/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:09:06 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/11 16:14:23 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ERROR__H
# define __ERROR__H

#define ER_ARG "Error : Invalid Number Of Arguments"
#define ER_INFILE "Error : No such file or directory: "
#define ER_OUTFILE "Eroror : Can't create file : "
int		ft_error(char *err);
void	print_err(char *err);

#endif
