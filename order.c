#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	t_stack	*max;

	max = ft_findmax(*a);
	if (!ft_stackorder(*a))
	{
		if (*a == max)
		{
			ft_rotatenode(a);
			ft_putstr("ra\n");
		}
		else if ((*a)->next == max)
		{
			ft_rever_rotatenode(a);
			ft_putstr("rra\n");
		}
		if ((*a)->dataarg > (*a)->next->dataarg)
		{
			ft_swapnode(a);
			ft_putstr("sa\n");
		}
	}
}

void	ft_sort_pb(t_stack **a, t_stack **b)
{
	t_stack	*cost;
	int		len;

	len = ft_lstlen_ps(*a);
	while (len-- > 3 && !ft_stackorder(*a))
	{
		ft_stack_median(*a);
		ft_stack_median(*b);
		cost = ft_cheapest(a, b);
		ft_stack_top_head(a, b, cost);
		ft_push(a, b, MOVEPB);
	}
}

void	ft_sort_pa(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	int		len;

	len = ft_lstlen_ps(*b);
	while (len-- > 0)
	{
		ft_stack_median(*a);
		ft_stack_median(*b);
		node_b = ft_set_b(*a, *b);
		while (*a != node_b)
		{
			if (node_b->median)
				ft_rotate(a, b, MOVERA);
			else
				ft_rever_rotate(a, b, MOVERRA);
		}
		ft_push(a, b, MOVEPA);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstlen_ps(*a);
	if (len-- > 3 && !ft_stackorder(*a))
		ft_push(a, b, MOVEPB);
	if (len-- > 3 && !ft_stackorder(*a))
		ft_push(a, b, MOVEPB);
	ft_sort_pb(a, b);
	ft_sort_three(a);
	ft_sort_pa(a, b);
	ft_stack_median(*a);
	ft_revise_end(a, b);
}

void	ft_revise_end(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = ft_findmin(*a);
	while (*a != min)
	{
		if (min->median)
			ft_rotate(a, b, MOVERA);
		else
			ft_rever_rotate(a, b, MOVERRA);
	}
}