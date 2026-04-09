/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:22:07 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 17:11:04 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cmds = NULL;
	data->tokens = NULL;
	data->parsed_cmd = NULL;
	data->p_token = NULL;
	data->envp = NULL;
	data->exec_code = 0;
	data->exit_status = 0;
	return (data);
}

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->cmds)
			ft_lstclear(&data->cmds, free_cmd);
		data->cmds = NULL;
		if (data->tokens)
			ft_lstclear(&data->tokens, free);
		data->tokens = NULL;
	}
}
