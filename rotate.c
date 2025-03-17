#include "./push_swap.h"

static void	ft_rotate(t_stack **stacks)
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

void	ra(t_stack **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
