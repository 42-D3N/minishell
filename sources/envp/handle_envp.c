/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:59:04 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 15:56:33 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_envname(char *env)
{
	int		i;
	char	*name;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	name = ft_substr(env, 0, i);
	if (!name)
		return (NULL);
	return (name);
}

static char	*get_envvalue(char *env)
{
	char	*value;
	char	*value_dup;

	value = ft_strchr(env, '=');
	if (!value)
		return (NULL);
	value++;
	value_dup = ft_strdup(value);
	if (!value_dup)
		return (NULL);
	return (value_dup);
}

char	*findenv(char *envname, t_list **envp)
{
	t_list	*env;
	char	*name;
	char	*value;

	env = *envp;
	while (env)
	{
		name = get_envname(env->content);
		if (!name)
			return (NULL);
		if (p_strcmp(name, envname))
		{
			value = get_envvalue(env->content);
			return (free(name), value);
		}
		free(name);
		env = env->next;
	}
	return (NULL);
}

char	*get_env_and_find(char *envname)
{
	t_list	*envp;
	char	*value;

	envp = restore_envp();
	if (!envp)
		return (NULL);
	value = findenv(envname, &envp);
	ft_lstclear(&envp, free);
	return (value);
}

int	store_envp(t_list *envp)
{
	int		envp_fd;

	envp_fd = open("/tmp/.mctw.envp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (envp_fd == -1)
		return (0);
	while (envp)
	{
		write(envp_fd, envp->content, ft_strlen(envp->content));
		write(envp_fd, "\n", 1);
		envp = envp->next;
	}
	close(envp_fd);
	return (1);
}
