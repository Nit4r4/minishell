/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:48:05 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/23 15:58:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_d(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (ft_putstr_s("-2147483648"));
	else if (nbr < 0)
	{
		count += ft_putchar_c('-');
		count += ft_putnbr_d(-nbr);
	}
	else if (nbr > 9)
	{
		count += ft_putnbr_d(nbr / 10);
		count += ft_putnbr_d(nbr % 10);
	}
	else
		count += ft_putchar_c((nbr + 48));
	return (count);
}
