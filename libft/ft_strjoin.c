/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:20:22 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:23 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*sjoin;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	sjoin = (char *)malloc((sizeof(char) * (s1len + s2len) + 1));
	if (!sjoin)
		return (0);
	ft_strlcpy(sjoin, s1, s1len + 1);
	ft_strlcat(sjoin, s2, s1len + s2len + 1);
	return (sjoin);
}

// int	main(void)
// {
// 	char *res = ft_strjoin("hello", " world");
// 	printf("%s", res);
// 	return (0);
// }