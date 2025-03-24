#include "./push_swap.h"

void	ft_pushnode(t_stack **dest, t_stack **src)
{
	t_stack *push;

	if (!dest || !(*src))
		return ;
	push = *src;
	*src = (*src)->next;
	if (!(*dest))
	{
		*dest = push;
		(*dest)->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->prev = NULL;
		if (*src)
			(*src)->prev = NULL;
		(*dest)->prev = push;
		*dest = push;
	}
}

void	ft_push(t_stack **a,t_stack **b, int move)
{
	if (move == MOVEPA)
	{
		ft_pushnode(a, b);
		ft_putstr("pa\n");
	}
	if (move == MOVEPB)
	{
		ft_pushnode(a, b);
		ft_putstr("pb\n");
	}
}
