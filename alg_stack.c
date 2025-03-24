#include "push_swap.h"

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