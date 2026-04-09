/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_putnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:06 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:39:19 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"
#include <unistd.h>

static int	printnbr(int nb, int count, int fd)
{
	if (nb != 0)
	{
		count = printnbr(nb / 10, count, fd);
		count += ft_dprintf_putchar(nb % 10 + 48, fd);
	}
	return (count);
}

int	ft_dprintf_putnbr(int nb, int fd)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		count = 11;
	}
	else if (nb == 0)
	{
		write(fd, "0", 1);
		count = 1;
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
			count += 1;
		}
		count = printnbr(nb, count, fd);
	}
	return (count);
}
