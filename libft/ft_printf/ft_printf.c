/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:35 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:28:27 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			count += ft_handle(s[++i], args);
		else
			count += ft_printf_putchar(s[i]);
		i++;
	}
	va_end (args);
	return (count);
}
