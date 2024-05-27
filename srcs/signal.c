/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldrolet <oldrolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:39:50 by oldrolet          #+#    #+#             */
/*   Updated: 2024/05/27 17:39:51 by oldrolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_int_handler(int signal)
{
	(void)signal;
	rl_on_new_line();
	kill(0, 0);
}

void	ft_quit_handler(int signal)
{
	(void)signal;
	kill(0, 0);
}

void	ft_doc_sig_handle(int signal)
{
	(void)signal;
	ft_putendl_fd("\0", 1);
	exit(1);
}

void	interactive_shell(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signal_handler_parent(int mode)
{
	if (mode == INTERACTIVE)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &interactive_shell);
	}
	else if (mode == CHILD)
	{
		signal(SIGQUIT, &ft_quit_handler);
		signal(SIGINT, &ft_int_handler);
	}
	else if (mode == HD_SIG)
	{
		signal(SIGINT, &ft_doc_sig_handle);
		signal(SIGQUIT, SIG_IGN);
	}
}
