/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:14:23 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/05 17:37:10 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*read_to_char(int fd)
{
	char	*s1;
	char	*s2;
	char	*content;

	s2 = "init";
	content = NULL;
	while (s2)
	{
		s2 = get_next_line(fd);
		if (s2)
		{
			if (content)
				s1 = ft_strdup(content);
			else
				s1 = ft_strdup("");
			free(content);
			content = ft_strjoin(s1, s2);
			free(s1);
			free(s2);
			if (!content)
				return (NULL);
		}
	}
	return (content);
}

char	*get_content(char *path)
{
	char	*content;
	int		content_fd;
	char	*full_path;

	full_path = ft_strjoin("/tmp/", path);
	if (!full_path)
		return (NULL);
	content_fd = open(full_path, O_RDONLY, 0644);
	free(full_path);
	if (content_fd == -1)
		return (NULL);
	content = read_to_char(content_fd);
	close(content_fd);
	if (!content)
		return (NULL);
	return (content);
}

int	store_content(char *path, char *content)
{
	int		content_fd;
	char	*full_path;

	full_path = ft_strjoin("/tmp/", path);
	if (!full_path)
		return (0);
	content_fd = open(full_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(full_path);
	if (content_fd == -1)
		return (0);
	write(content_fd, content, ft_strlen(content));
	close(content_fd);
	return (1);
}
