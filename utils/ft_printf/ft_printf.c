/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:15:17 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/26 14:15:04 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_eval_format(int i, const char *str, va_list ap)
{
	if (str[i] == 'c')
		return (ft_putchar_c(va_arg(ap, int)));
	else if (str[i] == 's')
		return (ft_putstr_s(va_arg(ap, char *)));
	else if (str[i] == 'p')
		return (ft_ptr_p((unsigned long)va_arg(ap, void *)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_d(va_arg(ap, int)));
	else if (str[i] == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_printfhex_x(va_arg(ap, unsigned int), str[i]));
	else if (str[i] == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar_c(format[i]);
		else
			count += ft_eval_format(++i, format, ap);
		i++;
	}
	va_end(ap);
	return (count);
}
