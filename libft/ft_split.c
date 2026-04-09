/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:19:41 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/01/30 14:21:29 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

static int	freearray(char **s, int index)
{
	while (index--)
		free(s[index]);
	free(s);
	return (0);
}

static int	split_words(char const *s, char c, char **splits)
{
	int	i;
	int	count;
	int	isword;

	i = 0;
	count = -1;
	isword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (isword++ == 0)
				count++;
		}
		if (isword > 0 && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			splits[count] = ft_substr(s, i - isword + 1, isword);
			if (!splits[count])
				return (freearray(splits, count));
			isword = 0;
		}
		i++;
	}
	splits[count + 1] = NULL;
	return (1);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	inword;

	i = 0;
	count = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (inword == 0)
			{
				count++;
				inword++;
			}
		}
		else
			inword = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		nbwords;
	char	**splits;

	nbwords = count_words(s, c);
	splits = (char **) malloc((sizeof(char *) * (nbwords + 1)));
	if (!splits)
		return (0);
	if (!split_words(s, c, splits))
		return (0);
	return (splits);
}

// int	main(void)
// {
// 	int i = 0;
// 	char **res = ft_split("bonjour je suis une phrase", ' ');
// 	while (res[i] != NULL)
// 	{
// 		printf("%s", res[i]);
// 		i++;
// 	}
// 	return (0);
// }