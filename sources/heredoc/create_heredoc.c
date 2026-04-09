/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:50:26 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/05 17:51:59 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../includes/minishell.h"

static char	*random_name(int fd, const char *charset)
{
	char			*name;
	int				i;
	unsigned char	byte;

	name = malloc(17);
	if (!name)
		return (NULL);
	ft_strlcpy(name, ".mctw.tmp-", 11);
	i = 0;
	while (i < 6)
	{
		if (read(fd, &byte, 1) != 1)
			return (free(name), NULL);
		name[10 + i] = charset[byte % (ft_strlen(charset))];
		i++;
	}
	name[10 + i] = '\0';
	return (name);
}

static char	*find_valid_name(int fd)
{
	char	*filename;
	char	*filepath;

	filename = random_name(fd, CHARSET);
	if (!filename)
		return (0);
	filepath = ft_strjoin("/tmp/", filename);
	if (!filepath)
		return (free(filename), NULL);
	while (!access(filepath, F_OK))
	{
		free(filename);
		free(filepath);
		filename = random_name(fd, CHARSET);
		if (!filename)
			return (0);
		filepath = ft_strjoin("/tmp/", filename);
		if (!filepath)
			return (free(filename), NULL);
	}
	free(filename);
	return (filepath);
}

char	*create_tmp(void)
{
	int		fd;
	char	*tmp_file;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp_file = find_valid_name(fd);
	close(fd);
	if (!tmp_file)
		return (NULL);
	return (tmp_file);
}
