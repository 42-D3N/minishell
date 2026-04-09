/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:19:24 by tle-pape          #+#    #+#             */
/*   Updated: 2025/06/10 11:50:40 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_sig = SIGUSR1;

void	welcome(void)
{
	printf("\n\n\e[8mQUE FAITES VOUS ICI ?!\e[28m\n");
	printf("\e[38:5:42mBienvenue, cher visiteur, au sein du mini-chef\n");
	printf("\t     Codé par Creeps & D3N\e[39m\n");
	printf("\e[53m\e[5m\e[31mVer.NaN\e[25m\e[39m\e[55m\n\n");
}

void	clean_exit(t_data *d, char *s)
{
	int	status;

	status = 0;
	if (s)
		free(s);
	if (d)
	{
		status = d->exit_status;
		ft_lstclear(&d->envp, free);
		free(d);
	}
	rl_clear_history();
	exit(status);
}

t_list	*call_prompt(char *prompt, t_data *d)
{
	char	*s;
	t_list	*cmds;

	d->exec_code = 0;
	d->cmds = NULL;
	d->tokens = NULL;
	g_sig = SIGUSR1;
	s = prompt_loop(prompt, 0);
	if (!s)
		clean_exit(d, NULL);
	if (g_sig == SIGINT)
		d->exit_status = SIGINT + 128;
	cmds = NULL;
	add_history(s);
	g_sig = SIGUSR2;
	banana_split(s, d);
	if (d->exec_code == FATAL)
		clean_exit(d, NULL);
	else if (d->exec_code == ERROR)
		return (NULL);
	cmds = d->cmds;
	return (cmds);
}

int	main(int argc, char **argv, char **envp)
{
	t_list	*cmds;
	t_data	*d;

	(void)argv;
	if (argc != 1)
		return (0);
	if (!set_handlers())
		return (0);
	d = init_data();
	if (!d)
		clean_exit(NULL, NULL);
	d->envp = init_env(envp);
	if (!d->envp)
		clean_exit(d, NULL);
	welcome();
	while (1)
	{
		cmds = call_prompt(BPROMPT"mini-chef :"TPROMPT, d);
		if (cmds)
			cmd_go(cmds, &d);
	}
	return (0);
}
