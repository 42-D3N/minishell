/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_putstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:40:19 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:29:49 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"
#include <unistd.h>

int	ft_dprintf_putstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
	return (i);
}
