/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:56:12 by vferraro          #+#    #+#             */
/*   Updated: 2022/09/20 16:04:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv, char **env)
{
/*
  ETAPE 1 PROMPT
  faisons le simple principe d’afficher un prompt qui lit des
  commandes et fait rien (pour l’instant) puis qui se raffiche.
*/
	while (42)
	{
		ft_putstr_fd("mon_prompt>");
		get_next_line(0);
	}
}
