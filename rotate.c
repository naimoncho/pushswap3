#include "./push_swap.h"

void	ft_rotatenode(t_stack **stacks)
{
	t_stack	*firstnode;
	t_stack *lstnode;

	if (!*stacks || !(*stacks)->next)
		return ;
	firstnode = *stacks;
	lstnode = ft_lstlast_ps(*stacks);
	*stacks = firstnode->next;
	(*stacks)->prev = NULL;
	lstnode->next = firstnode;
	firstnode->next = NULL;
	firstnode->prev = lstnode;
}

void	ft_rotate(t_stack **a,t_stack **b, int move)
{
	if (move == MOVERA)
	{
		ft_rotatenode(a);
		ft_putstr("ra\n");
	}
	else if (move == MOVERB)
	{
		ft_rotatenode(b);
		ft_putstr("rb\n");
	}
	if (move == MOVERR)
	{
		ft_rotatenode(a);
		ft_rotatenode(b);
		ft_putstr("rr\n");
	}
}
