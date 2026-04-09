/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:29:24 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 15:55:14 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_nb_lines(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**read_to_charchar(int fd)
{
	char	**content;
	char	*s;
	int		i;

	content = malloc((get_nb_lines("/tmp/.mctw.envp") + 1) * sizeof(char *));
	if (!content)
		return (NULL);
	i = 0;
	s = "init";
	while (s)
	{
		s = get_next_line(fd);
		if (s && s[ft_strlen(s) - 1] == '\n')
			ft_strlcpy(s, s, ft_strlen(s));
		content[i++] = s;
	}
	return (content);
}

t_list	*init_env(char **envp)
{
	int		i;
	t_list	*env;
	t_list	*var;
	char	*s;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		s = ft_strdup(envp[i]);
		if (!s)
			return (ft_lstclear(&env, free), NULL);
		var = ft_lstnew(s);
		if (!var)
			return (free(s), ft_lstclear(&env, free), NULL);
		ft_lstadd_back(&env, var);
		i++;
	}
	return (env);
}

t_list	*restore_envp(void)
{
	char	**envp;
	t_list	*envp_list;
	int		envp_fd;

	envp_fd = open("/tmp/.mctw.envp", O_RDONLY);
	if (envp_fd == -1)
		return (NULL);
	envp = read_to_charchar(envp_fd);
	close(envp_fd);
	if (!envp)
		return (NULL);
	envp_list = init_env(envp);
	ft_arrfree((void **)envp);
	return (envp_list);
}
