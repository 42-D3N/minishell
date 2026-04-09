/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:39:25 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/06/10 11:50:52 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	disable_sigquit_echo(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void	enable_sigquit_echo(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_cc[VQUIT] = 28;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

char	*prompt_loop(char *prompt, int mode)
{
	char	*s;

	s = ft_strdup("");
	if (!s)
		return (NULL);
	while (ft_strlen(s) == 0)
	{
		free(s);
		disable_sigquit_echo();
		s = readline(prompt);
		enable_sigquit_echo();
		if (!s)
			return (NULL);
		if (mode)
			return (s);
	}
	return (s);
}
