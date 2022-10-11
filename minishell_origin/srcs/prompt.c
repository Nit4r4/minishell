/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:56:12 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/22 14:59:42 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* TEST */
// int main()
// {
// 	char    buffer[50];

// 	printf("\nInterpreteur de commande\nTaper \"exit\" pour quitter\n");
// 	while(1)
// 	{
// 		printf("Prompt : ");
// 		scanf("%s",buffer);
// 		if (strcmp("exit",buffer)==0)
// 		{
// 			exit(0);
// 		}
// 		else
// 		{
// 			printf("Commande inconnue ...\n");
// 		}
// 	}
// }

/* CLAIRE */
// while (42)
// 		{
// 			ft_init_struct(&data);
// 			data.str_rl = readline("$ ");
// 			if (!data.str_rl)
// 				break ;
// 			ft_infinity_while(&data);
// 		}
// //En gros, il enregistre le $, chez toi c'est "prompt" dans une variable
// if (argc == 1)
// 	{
// 		while (1)
// 		{
// 			ft_init_struct(&data);
// 			data.str_rl = readline("$ ");
// 			if (!data.str_rl)
// 				break ;
// 			ft_infinity_while(&data);
// 		}
// 		tcsetattr(STDIN_FILENO, TCSANOW, &sig);
// 	}
// 	else
// 		printf("Error argument\n");

void	welcome_in_our_prompt(void)
{
	char	*a;
	char	*b;
	char	*c;
	
	a = " (|)_(|)";
	b = " (='.'=)     */ welcome in our prompt \\*";
	c = "('')-('')           V + C = 💛";
	ft_printf ("\n");
	ft_printf ("%s\n", a);
	ft_printf ("%s\n", b);
	ft_printf ("%s\n", c);
	ft_printf ("\n");
}

int	main(void)
{
/*
  ETAPE 1 PROMPT
  faisons le simple principe d’afficher un prompt qui lit des
  commandes et fait rien (pour l’instant) sortir avec ctrl + c.
*/
	welcome_in_our_prompt();
	while (42)
	{
		ft_putstr_fd("$ ", 1);
		ft_no_one("test");
		readline(0);
	}
	return (0);
}
