/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dhandle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:39:45 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:38:58 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"
#include <unistd.h>

int	ft_dhandle(char conv, va_list args, int fd)
{
	if (conv == 'c')
		return (ft_dprintf_putchar(va_arg(args, int), fd));
	else if (conv == 's')
		return (ft_dprintf_putstr(va_arg(args, char *), fd));
	else if (conv == 'p')
		return (ft_dprintf_putpointer(va_arg(args, long), fd));
	else if (conv == 'd' || conv == 'i')
		return (ft_dprintf_putnbr(va_arg(args, int), fd));
	else if (conv == 'u')
		return (ft_dprintf_putuint(va_arg(args, unsigned int), fd));
	else if (conv == 'x')
		return (ft_dprintf_puthex(va_arg(args, unsigned long), 87, fd));
	else if (conv == 'X')
		return (ft_dprintf_puthex(va_arg(args, unsigned long), 55, fd));
	else if (conv == '%')
		return (ft_dprintf_putchar('%', fd));
	else
		return (ft_dprintf_putchar(conv, fd));
}
