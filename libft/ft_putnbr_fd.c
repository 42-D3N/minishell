/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:20:03 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/07 10:31:29 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_rec(int nb, int fd)
{
	if (nb != 0)
	{
		putnbr_rec(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if (nb == -2147483648)
		ft_putstr_fd("2147483648", fd);
	else if (nb == 0)
		ft_putchar_fd('0', fd);
	else
		putnbr_rec(nb * ((nb >= 0) - (nb < 0)), fd);
}
