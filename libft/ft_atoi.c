/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:12:39 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 13:53:01 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * neg);
}

// int	main(void)
// {
//	printf("%d", ft_atoi("1324"));
// 	return (0);
// }