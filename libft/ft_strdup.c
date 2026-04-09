/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:20:14 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:54:19 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dup;

	slen = ft_strlen(s);
	dup = (char *) malloc((sizeof(char) * slen) + 1);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, slen + 1);
	return (dup);
}
