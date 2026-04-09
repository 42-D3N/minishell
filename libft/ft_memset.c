/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:18:29 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/03 12:18:29 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = s;
	c = (char)c;
	while (n--)
	{
		*ptr = c;
		ptr++;
	}
	return (s);
}
