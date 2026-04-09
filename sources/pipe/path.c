/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:26:18 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/07 16:10:39 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_is_cmd(char *cmd)
{
	int		i;
	char	*final;
	char	**strs;
	char	**s_env;

	i = 0;
	strs = ft_calloc(sizeof(char *), 4);
	s_env = ft_split(getenv("PATH"), ':');
	strs[1] = "/";
	strs[2] = cmd;
	strs[3] = NULL;
	while (i != -1 && s_env[i])
	{
		strs[0] = s_env[i++];
		final = multi_join(strs);
		if (access(final, F_OK & X_OK) == 0)
			break ;
		else
			final = null_free(final);
	}
	ft_arrfree((void **)s_env);
	strs = null_free(strs);
	if (final)
		return (final);
	return (NULL);
}

int	is_bash_exec(char *path)
{
	int		fd;
	char	buffer[5];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, buffer, 4) <= 0)
		return (close(fd), 0);
	close(fd);
	buffer[4] = '\0';
	return (p_strcmp(buffer, "\x7f\x45\x4c\x46"));
}

int	ft_is_file(char *s)
{
	DIR	*dir;

	if (access(s, F_OK) == 0)
	{
		dir = opendir(s);
		if (!dir)
			return (1);
		else
		{
			closedir(dir);
			return (2);
		}
	}
	return (0);
}

char	*get_full_path(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (cmd_path[i])
	{
		tmp = ft_strjoin(cmd_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			ft_arrfree((void **)cmd_path);
			cmd_path = NULL;
			return (path);
		}
		free(path);
		i++;
	}
	ft_arrfree((void **)cmd_path);
	cmd_path = NULL;
	return (NULL);
}

char	*get_path(t_list *envp, char *cmd)
{
	char	*cmd_r;
	char	**cmdpath;
	t_list	*lstnext;

	lstnext = envp;
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (lstnext && ft_strncmp("PATH=", (char *)lstnext->content, 5))
		lstnext = lstnext->next;
	if (!lstnext)
		return (NULL);
	cmdpath = ft_split((char *)lstnext->content + 5, ':');
	cmd_r = get_full_path(cmdpath, cmd);
	return (cmd_r);
}
