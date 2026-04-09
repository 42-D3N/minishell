/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:35 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:38:32 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *s, ...)
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
			count += ft_dhandle(s[++i], args, fd);
		else
			count += ft_dprintf_putchar(s[i], fd);
		i++;
	}
	va_end (args);
	return (count);
}
