/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:47:50 by abeaudet          #+#    #+#             */
/*   Updated: 2022/12/21 14:48:11 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  BUFSIZ
# endif

int		ft_endline(const char *a);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_malloc(size_t a, size_t b);
char	*ft_strdup(const char *s1);
void	ft_free(char **str, char **str2, char **str3);
char	*ft_preline(const char *s);
char	*ft_postline(const char *s);
void	ft_read(int fd, char **str, char **temp);
char	*ft_lookline(char **buffer, char **temp);
char	*get_next_line(int fd);

#endif