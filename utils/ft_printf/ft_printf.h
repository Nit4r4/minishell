/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:56:47 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/26 14:08:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# define PRINTF_VALID_FORMATS "cspdiuxX%"

int	ft_putchar_c(char c);
int	ft_putstr_s(char *s);
int	ft_ptr_p(unsigned long p);
int	ft_putnbr_d(int nbr);
int	ft_printf_u(unsigned int u);
int	ft_printfhex_x(unsigned long x, char arg);
int	ft_printf(const char *format, ...);

#endif
