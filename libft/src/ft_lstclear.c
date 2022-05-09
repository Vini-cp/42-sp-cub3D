/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:19:21 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:46:26 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next_node;

	next_node = NULL;
	while ((*lst) != NULL)
	{
		next_node = (*lst)->next;
		free(*lst);
		(*lst) = next_node;
	}
}
