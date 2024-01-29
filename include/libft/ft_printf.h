/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:25:09 by abeaudet          #+#    #+#             */
/*   Updated: 2022/11/10 13:43:17 by abeaudet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <xlocale.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_typestring(char *str);
int		ft_hexaprint(unsigned int num, const char k);
int		ft_printnbr(int n);
char	*ft_itoa(int n);
int		ft_percent(void);
int		ft_unsigned(unsigned int n);
int		ft_ptr(unsigned long int nbr, int recall);
int		ft_printf(const char *str, ...);

#endif
