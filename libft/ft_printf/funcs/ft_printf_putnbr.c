/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:06 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:30:00 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	printnbr(int nb, int count)
{
	if (nb != 0)
	{
		count = printnbr(nb / 10, count);
		count += ft_printf_putchar(nb % 10 + 48);
	}
	return (count);
}

int	ft_printf_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			write(1, "-", 1);
			count += 1;
		}
		count = printnbr(nb, count);
	}
	return (count);
}
