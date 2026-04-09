/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:53:28 by wskrzyni          #+#    #+#             */
/*   Updated: 2024/11/05 10:40:24 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mappeds;
	int		i;

	mappeds = ft_strdup(s);
	if (mappeds == NULL)
		return (NULL);
	i = 0;
	while (mappeds[i] != '\0')
	{
		mappeds[i] = f(i, mappeds[i]);
		i++;
	}
	return (mappeds);
}
