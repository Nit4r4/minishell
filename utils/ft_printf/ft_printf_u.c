/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:50:52 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/23 15:51:10 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf_u(unsigned int u)
{
	int	count;

	count = 0;
	if (u < 0)
	{
		u -= UINT_MAX - 1;
		count += ft_printf_u(u);
	}
	if (u == 0)
		return (write (1, "0", 1));
	if (u > 0 && u < 10)
		count += ft_putchar_c(u + 48);
	else if (u > 9)
	{
		count += ft_putnbr_d(u / 10);
		count += ft_putnbr_d(u % 10);
	}
	return (count);
}
