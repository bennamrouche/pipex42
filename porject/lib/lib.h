/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:54:20 by ebennamr          #+#    #+#             */
/*   Updated: 2022/12/19 15:57:11 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

//error messages
# define ER_ARG "Error : Invalid Number Of Arguments"
# define ER_INFILE "Error : No such file or directory: "
# define ER_OUTFILE "Eroror : Can't create file : "
# define ER_FORK "Error: fork can't create child porcess ): "
# define ER_CMD_NT "Error: command not found: "
# define ER_PIPE "Error : pipe not created !"

size_t		ft_strlen(const char *str);
int			ft_strncmp(char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int x);
char		*ft_strjoin(char const *string1, char const *string2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_error(char *err);
void		print_err(char *str1, char *str2);
#endif
