/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:07:21 by vferraro          #+#    #+#             */
/*   Updated: 2021/11/10 11:13:57 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tempo;

	if (del && *lst && lst)
	{
		while (*lst && lst)
		{
			tempo = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tempo;
		}
		*lst = NULL;
	}
}
