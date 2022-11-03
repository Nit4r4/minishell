/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeur_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:26:44 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/23 15:55:59 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_ptr_p(unsigned long p)
{
	int	count;

	count = ft_putstr_s("0x");
	count += ft_printfhex_x(p, 'x');
	return (count);
}
