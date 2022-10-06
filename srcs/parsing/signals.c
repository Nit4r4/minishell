/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:16:50 by creyt             #+#    #+#             */
/*   Updated: 2022/10/06 14:22:06 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	display_prompt_block(int num)
{
	num++;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	display_prompt_block_exit(int num)
{
	num++;
	write(1, "Quit 3\n", 7);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	define_input_signals_block(void)
{
	signal(SIGINT, display_prompt_block);
	signal(SIGQUIT, display_prompt_block_exit);
}

void	display_prompt(int num)
{
	num++;
	ft_static(1);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	define_input_signals(void)
{
	signal(SIGINT, display_prompt);
	signal(SIGQUIT, SIG_IGN);
}