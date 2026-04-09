/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:41:33 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/04 21:00:47 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*cwd(void)
{
	char			*buffer;
	static int		i = 20;

	buffer = malloc(i);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, i);
	while (!getcwd(buffer, i))
	{
		free(buffer);
		buffer = malloc(++i);
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, i);
	}
	return (buffer);
}

void	ft_pwd(void)
{
	char	*cwdstr;

	cwdstr = cwd();
	if (!cwdstr)
		return ;
	printf("%s\n", cwdstr);
	free(cwdstr);
}
