/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:09:06 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/15 20:19:40 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define ER_ARG "Error : Invalid Number Of Arguments"
# define ER_INFILE "Error : No such file or directory: "
# define ER_OUTFILE "Eroror : Can't create file : "
# define ER_FORK "Error: fork can't create child porcess ): "
# define ER_CMD_NT "Error: command not found: "
# define ER_PIPE "Error : pipe not created !"

int		ft_error(char *err);
void	print_err(char *err);

#endif
