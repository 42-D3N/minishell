/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putpointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:13 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:30:18 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	abslt(int nb)
{
	return (nb * ((nb >= 0) - (nb < 0)));
}

static int	ft_putchar_hex(unsigned long nb, int cptl)
{
	if (nb <= 9)
		return (ft_printf_putchar(nb + 48));
	else
		return (ft_printf_putchar(nb + cptl));
}

static int	printnbr(unsigned long nb, int count, int cptl)
{
	if (nb != 0)
	{
		count = printnbr(nb / 16, count, cptl);
		count += ft_putchar_hex(abslt(nb % 16), cptl);
	}
	return (count);
}

int	ft_printf_putpointer(unsigned long p)
{
	int	count;

	count = 0;
	if ((void *)p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = printnbr(p, count, 87);
	return (2 + count);
}
