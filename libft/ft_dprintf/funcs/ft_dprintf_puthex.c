/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_puthex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:00 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:40:17 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"
#include <unistd.h>

static int	ft_putchar_hex(unsigned int nb, int cptl, int fd)
{
	if (nb <= 9)
		return (ft_dprintf_putchar(nb + 48, fd));
	else
		return (ft_dprintf_putchar(nb + cptl, fd));
}

static int	printnbr(unsigned int nb, int count, int cptl, int fd)
{
	if (nb != 0)
	{
		count = printnbr(nb / 16, count, cptl, fd);
		count += ft_putchar_hex(nb % 16, cptl, fd);
	}
	return (count);
}

int	ft_dprintf_puthex(unsigned int nb, int cptl, int fd)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		count = 1;
	}
	else
		count = printnbr(nb, count, cptl, fd);
	return (count);
}
