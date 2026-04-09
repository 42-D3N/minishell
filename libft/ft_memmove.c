/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:19:54 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:25 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	if (!cdest && !csrc)
		return (0);
	if (cdest < csrc)
		while (n--)
			*cdest++ = *csrc++;
	if (cdest > csrc)
	{
		cdest += n - 1;
		csrc += n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	return (dest);
}
