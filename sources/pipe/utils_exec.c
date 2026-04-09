/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:36:52 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/09 13:13:48 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_outfd(t_exec_d *ed, int pipe_fd[2], int fd)
{
	if (ed->node->outpath && *ed->node->outpath)
	{
		close(pipe_fd[1]);
		fd = open(ed->node->outpath, O_WRONLY | O_APPEND);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (ed->node->isnext == true)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	else
		close(pipe_fd[1]);
}

void	handle_infd(t_exec_d *ed, int fd)
{
	if (ed->node->inpath && *ed->node->inpath)
	{
		if (ed->node->infd != -1)
			close(ed->node->infd);
		fd = open(ed->node->inpath, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (ed->node->infd != -1)
	{
		dup2(ed->node->infd, STDIN_FILENO);
		close(ed->node->infd);
	}
	else if (ed->node->inpath && !*ed->node->inpath)
	{
		free(ed->node->cmdpath);
		ft_arrfree((void **)ed->node->args);
		ed->node->args = ft_split("exit 1", ' ');
		ed->node->cmdpath = ft_strdup("exit");
	}
}

char	**tab_envp(t_list *t_envp)
{
	int		i;
	int		envp_len;
	char	**envp;
	t_list	*mock_envp;

	i = 0;
	mock_envp = t_envp;
	envp_len = ft_lstsize(mock_envp);
	envp = ft_calloc((sizeof(char *)), envp_len + 1);
	while (mock_envp)
	{
		envp[i] = (char *)mock_envp->content;
		i++;
		mock_envp = mock_envp->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	*null_free(void	*fwee)
{
	free(fwee);
	return (NULL);
}

char	*multi_join(char **strs)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*final;

	i = 0;
	len = 1;
	while (strs[i])
		len += ft_strlen(strs[i++]);
	final = ft_calloc(sizeof(char), (len + i));
	i = 0;
	k = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			final[k++] = strs[i][j++];
		i++;
	}
	final[k] = '\0';
	return (final);
}
