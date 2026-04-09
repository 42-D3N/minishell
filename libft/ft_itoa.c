/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:19:26 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:19 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static int	get_nbrsize(int nb)
{
	int	count;

	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	ft_power(int nb, int power)
{
	int	b;

	b = 1;
	if (power < 0)
		return (0);
	while (power--)
		b *= nb;
	return (b);
}

static void	assign_loop(int nb, char *anb, int nbsize)
{
	int		divider;

	divider = ft_power(10, nbsize - 1);
	if (nb < 0)
		*anb++ = '-';
	nb = nb * ((nb >= 0) - (nb < 0));
	while (divider > 0)
	{
		*anb++ = (nb / divider) + 48;
		nb = nb % divider;
		divider /= 10;
	}
	*anb = '\0';
}

char	*ft_itoa(int nb)
{
	char	*anb;
	int		nbsize;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	nbsize = get_nbrsize(nb * ((nb >= 0) - (nb < 0)));
	anb = (char *) malloc((sizeof(char) * nbsize) + (nb < 0) + 1);
	if (!anb)
		return (0);
	assign_loop(nb, anb, nbsize);
	return (anb);
}

// int	main(void)
// {
//	printf("%s", ft_itoa(1324));
// 	return (0);
// }