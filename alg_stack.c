#include "push_swap.h"

void	ft_revise_end(t_stack **a)
{
	t_stack	*min;

	min = ft_findmin(*a);
	while (*a != min)
	{
		if (min->up_median)
			ra(a);
		else
			rra(a);
	}
}

void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstlen_ps(*a);
	if (len-- > 3 && !ft_stackorder(*a))
		pb(a, b);
	if (len-- > 3 && !ft_stackorder(*a))
		pb(a, b);
	ft_sort_pb(a, b);
	ft_sort_three(a);
	ft_sort_pa(a, b);
	ft_stack_median(*a);
	ft_revise_end(a);
}