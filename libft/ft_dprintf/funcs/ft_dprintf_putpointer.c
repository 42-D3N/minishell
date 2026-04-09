/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_putpointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:13 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:39:35 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"
#include <unistd.h>

static int	abslt(int nb)
{
	return (nb * ((nb >= 0) - (nb < 0)));
}

static int	ft_putchar_hex(unsigned long nb, int cptl, int fd)
{
	if (nb <= 9)
		return (ft_dprintf_putchar(nb + 48, fd));
	else
		return (ft_dprintf_putchar(nb + cptl, fd));
}

static int	printnbr(unsigned long nb, int count, int cptl, int fd)
{
	if (nb != 0)
	{
		count = printnbr(nb / 16, count, cptl, fd);
		count += ft_putchar_hex(abslt(nb % 16), cptl, fd);
	}
	return (count);
}

int	ft_dprintf_putpointer(unsigned long p, int fd)
{
	int	count;

	count = 0;
	if ((void *)p == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	write(fd, "0x", 2);
	count = printnbr(p, count, 87, fd);
	return (2 + count);
}
