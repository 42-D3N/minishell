/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:44:10 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/08 12:53:11 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	size_t	allsize;

	allsize = nmemb * size;
	temp = malloc(allsize);
	if (temp)
	{
		if (size > 0 && nmemb > 0)
			ft_bzero(temp, allsize);
		return (temp);
	}
	return (0);
}
