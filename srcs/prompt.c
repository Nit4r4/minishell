/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:56:12 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/22 13:13:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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


int main(void)
{
/*
  ETAPE 1 PROMPT
  faisons le simple principe d’afficher un prompt qui lit des
  commandes et fait rien (pour l’instant) sortir avec ctrl + c.
*/
	while (42)
	{
		ft_putstr_fd("🐥", 1);
		readline(0);
	}
	return (0);
}
