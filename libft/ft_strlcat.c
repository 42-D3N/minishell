/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:39:47 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:29 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	destsize;
	unsigned int	srcsize;

	i = 0;
	destsize = ft_strlen(dest);
	srcsize = ft_strlen(src);
	if (size == 0 || destsize > size)
		return (size + srcsize);
	if (!src[0])
		return (destsize);
	while (src[i] != '\0' && (destsize + i) < size - 1)
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = '\0';
	return (destsize + srcsize);
}
