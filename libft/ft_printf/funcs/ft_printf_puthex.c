/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:00 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:29:36 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	ft_putchar_hex(unsigned int nb, int cptl)
{
	if (nb <= 9)
		return (ft_printf_putchar(nb + 48));
	else
		return (ft_printf_putchar(nb + cptl));
}

static int	printnbr(unsigned int nb, int count, int cptl)
{
	if (nb != 0)
	{
		count = printnbr(nb / 16, count, cptl);
		count += ft_putchar_hex(nb % 16, cptl);
	}
	return (count);
}

int	ft_printf_puthex(unsigned int nb, int cptl)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	else
		count = printnbr(nb, count, cptl);
	return (count);
}
