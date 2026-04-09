/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:49:56 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/28 18:15:46 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr = '\0';
		ptr++;
	}
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static size_t	gnl_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	destsize;
	unsigned int	srcsize;

	i = 0;
	destsize = gnl_strlen(dest);
	srcsize = gnl_strlen(src);
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

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*sjoin;

	s1len = gnl_strlen(s1);
	s2len = gnl_strlen(s2);
	sjoin = (char *)malloc((sizeof(char) * (s1len + s2len) + 1));
	if (!sjoin)
		return (NULL);
	gnl_strlcpy(sjoin, s1, s1len + 1);
	gnl_strlcat(sjoin, s2, s1len + s2len + 1);
	return (free(s1), sjoin);
}
