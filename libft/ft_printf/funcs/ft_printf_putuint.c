/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putuint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:27 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/12 00:30:27 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

static int	printnbr(unsigned int nb, int count)
{
	if (nb != 0)
	{
		count = printnbr(nb / 10, count);
		count += ft_printf_putchar(nb % 10 + 48);
	}
	return (count);
}

int	ft_printf_putuint(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	else
		count += printnbr(nb, count);
	return (count);
}
