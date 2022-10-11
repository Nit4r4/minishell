/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhex_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:09:52 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/23 15:52:57 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printfhex_x(unsigned long x, char arg)
{
	int				letter;
	unsigned int	hex;
	int				count;

	count = 0;
	letter = 97;
	if (arg == 'X')
		letter = 65;
	if (x >= 16)
		count += ft_printfhex_x(x / 16, arg);
	hex = x % 16;
	if (hex > 9)
		count += ft_putchar_c((hex - 10) + letter);
	else
		count += ft_putchar_c(hex + 48);
	return (count);
}
