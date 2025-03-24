#include "push_swap.h"

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lstlen_ps(t_stack *stacks)
{
	int	counter;

	counter = 0;
	while (stacks)
	{
		counter++;
		stacks = stacks->next;
	}
	return (counter);
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