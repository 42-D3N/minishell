/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:20:32 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/06 20:11:33 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static int	setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	trimmedlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0' && setcheck(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (i);
	j = ft_strlen(s1) - 1;
	while (j > 0 && setcheck(s1[j], set))
		j--;
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		trimlen;
	size_t	i;
	char	*trimmeds1;

	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	i = 0;
	trimlen = trimmedlen(s1, set);
	while (s1[i] != '\0' && setcheck(s1[i], set))
		i++;
	trimmeds1 = ft_substr(s1, i, trimlen);
	return (trimmeds1);
}

// int	main(void)
// {
// 	char *res = ft_strtrim("xABCJe suis une phraseBCxA", "xABC");
// 	printf("%s", res);
// 	return (0);
// }