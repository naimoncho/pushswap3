#include "./push_swap.h"

void	ft_rever_rotatenode(t_stack **stacks)
{
	t_stack *lstnode;
	t_stack *prev_last;

	if (!*stacks || !(*stacks)->next)
		return ;
	prev_last = ft_lstlast_ps(*stacks)->prev;
	lstnode = ft_lstlast_ps(*stacks);
	if (!lstnode || !prev_last)
		return ;
	if(*stacks)
	{
		lstnode->prev = NULL;
		lstnode->next = *stacks;
		lstnode->next->prev = lstnode;
		prev_last->next = NULL;
		*stacks = lstnode;
	}
}

void	ft_rever_rotate(t_stack **a,t_stack **b, int move)
{
	if (move == MOVERRA)
	{
		ft_rever_rotatenode(a);
		ft_putstr("rra\n");
	}
	else if (move == MOVERRB)
	{
		ft_rever_rotatenode(b);
		ft_putstr("rrb\n");
	}
	else if (move == MOVERRR)
	{
		ft_rever_rotatenode(a);
		ft_rever_rotatenode(b);
		ft_putstr("rrr\n");
	}
}
