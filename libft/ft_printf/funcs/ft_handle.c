/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:39:45 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:27:21 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

int	ft_handle(char conv, va_list args)
{
	if (conv == 'c')
		return (ft_printf_putchar(va_arg(args, int)));
	else if (conv == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (conv == 'p')
		return (ft_printf_putpointer(va_arg(args, long)));
	else if (conv == 'd' || conv == 'i')
		return (ft_printf_putnbr(va_arg(args, int)));
	else if (conv == 'u')
		return (ft_printf_putuint(va_arg(args, unsigned int)));
	else if (conv == 'x')
		return (ft_printf_puthex(va_arg(args, unsigned long), 87));
	else if (conv == 'X')
		return (ft_printf_puthex(va_arg(args, unsigned long), 55));
	else if (conv == '%')
		return (ft_printf_putchar('%'));
	else
		return (ft_printf_putchar(conv));
}
