/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:20:36 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:50 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	sub = (char *) malloc((i * sizeof(char)) + 1);
	if (!sub)
		return (0);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int	main(void)
// {
// 	char *res = ft_substr("E.T. telephone maison", 5, 9);
// 	printf("%s", res);
// 	return (0);
// }