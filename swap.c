#include "./push_swap.h"

void	ft_swapnode(t_stack **top)
{
	t_stack *first;
	t_stack *second;

	if (!*top || !(*top)->next)
		return ;
	first = *top;
	second = (*top)->next;
	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*top = second;
}

void	ft_swap(t_stack **a,t_stack **b, int move)
{
	if (move == MOVESA)
	{
		ft_swapnode(a);
		ft_putstr("sa\n");
	}

	else if (move == MOVESB)
	{
		ft_swapnode(b);
		ft_putstr("sb\n");
	}
	if (move == MOVESS)
	{
		ft_swapnode(a);
		ft_swapnode(b);
		ft_putstr("ss\n");
	}
}
