/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:07:23 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:46:09 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	change_pwdvar(t_list *envp)
{
	char	*s1;
	char	*s2;

	s1 = findenv("PWD", &envp);
	if (!s1)
		ft_lstreplace_content(envp, "OLDPWD");
	else
	{
		s2 = ft_strjoin("OLDPWD=", s1);
		free(s1);
		if (!s2)
			return ;
		ft_lstreplace_content(envp, s2);
		free(s2);
	}
	s1 = cwd();
	if (!s1)
		return ;
	s2 = ft_strjoin("PWD=", s1);
	free(s1);
	if (!s2)
		return ;
	ft_lstreplace_content(envp, s2);
	free(s2);
}

static int	change_dir(char *path)
{
	struct stat	dir;

	if (access(path, F_OK) == -1)
		return (ft_dprintf(STDERR_FILENO, EPROMPT \
			"mini-fail :\001\e[24m\002 %s: No such file or directory\n"\
			"\001\e[97m\002", path), 1);
	else if (stat(path, &dir) == -1)
		return (ft_dprintf(STDERR_FILENO, EPROMPT \
			"mini-fail :\001\e[24m\002 %s: Can't access directory\n"\
			"\001\e[97m\002", path), 1);
	else if ((dir.st_mode & S_IFMT) != S_IFDIR)
		return (ft_dprintf(STDERR_FILENO, EPROMPT \
			"mini-fail :\001\e[24m\002 %s: Not a directory\n"\
			"\001\e[97m\002", path), 1);
	else if (chdir(path) < 0)
		return (ft_dprintf(STDERR_FILENO, EPROMPT \
			"mini-fail :\001\e[24m\002 %s: Can't access directory\n"\
			"\001\e[97m\002", path), 1);
	return (0);
}

int	ft_cd(t_list *envp, char **args)
{
	int		exit_status;
	char	*home;

	exit_status = 0;
	if (ft_arrsize((void **)args) > 2)
		return (ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002" \
			" Error : too many arguments, expected 2.\001\e[97m\002\n"), 1);
	if (ft_arrsize((void **)args) == 2)
	{
		exit_status = change_dir(args[1]);
		if (exit_status == 0)
			change_pwdvar(envp);
	}
	else
	{
		home = findenv("HOME", &envp);
		if (!home)
			ft_dprintf(STDERR_FILENO, EPROMPT"mini-fail :\001\e[24m\002 cd"\
				" : HOME not set\001\e[97m\002\n");
		else if (change_dir(home))
			change_pwdvar(envp);
		free(home);
	}
	return (exit_status);
}
