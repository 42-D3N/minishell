/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:51:55 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:37 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	little_size;

	i = 0;
	j = 0;
	little_size = ft_strlen(little);
	if (little_size == 0)
		return ((char *)big);
	while (big[j] != '\0' && j < size)
	{
		while (big[j + i] == little[i] && big[j + i] != '\0' && (j + i) < size)
			i++;
		if (i == little_size)
			return ((char *)&big[j]);
		i = 0;
		j++;
	}
	return (0);
}

// int	main(void)
// {
// 	char *res = ft_strnstr("bonjour ici la terre", "ici", 20);
// 	printf("%s", res);
// 	return (0);
// }