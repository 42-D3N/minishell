/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:25:57 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/07 19:05:19 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_sig;

static void	sigint_action(int sig)
{
	if (sig == SIGINT)
	{
		if (g_sig == SIGUSR1 || g_sig == SIGINT)
		{
			rl_replace_line("", 0);
			write(1, "\n", 1);
			rl_on_new_line();
			rl_redisplay();
			g_sig = SIGINT;
		}
		else if (g_sig == SIGUSR2)
		{
			g_sig = SIGINT;
		}
		else if (!g_sig)
			exit(sig + 128);
	}
	else if (g_sig == SIGUSR2 && sig == SIGQUIT)
		return ;
}

int	set_handlers(void)
{
	struct sigaction	a_sigint;

	ft_bzero(&a_sigint, sizeof(sigaction));
	a_sigint.sa_handler = &sigint_action;
	sigemptyset(&a_sigint.sa_mask);
	a_sigint.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &a_sigint, 0) == -1
		|| sigaction(SIGQUIT, &a_sigint, 0) == -1)
		return (0);
	return (1);
}
