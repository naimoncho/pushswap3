/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naimcheniounigomez <naimcheniounigomez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:46:29 by ncheniou          #+#    #+#             */
/*   Updated: 2025/03/24 22:33:19 by naimcheniou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(t_stack **stacks)
{
	t_stack	*current;

	while (*stacks)
	{
		current = (*stacks)->next;
		free(*stacks);
		*stacks = current;
	}
	free(stacks);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*aux;

	aux = ft_lstlast_ps(*lst);
	if (*lst != NULL)
	{
		new->prev = aux;
		new->next = NULL;
		aux->next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstnew_ps(int index, long num)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->index	 = index;
	node->dataarg = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}