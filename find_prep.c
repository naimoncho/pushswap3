#include "push_swap.h"

t_stack	*ft_findmin(t_stack *stacks)
{
	long	min;
	t_stack	*min_node;

	min = INT_MAX;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg < min)
		{
			min_node = stacks;
			min = stacks->dataarg;
		}
		stacks = stacks->next;
	}
	return (min_node);
}

t_stack	*ft_findmax(t_stack *stacks)
{
	long	max;
	t_stack	*max_node;

	max = INT_MIN;
	if (!stacks)
		return (NULL);
	while (stacks)
	{
		if (stacks->dataarg > max)
		{
			max_node = stacks;
			max = stacks->dataarg;
		}
		stacks = stacks->next;
	}
	return (max_node);
}

t_stack	*ft_lowercost(t_stack *stacks)
{
	t_stack	*best_node;
	int		best_score;
	int		moves;

	best_node = NULL;
	best_score = INT_MAX;
	while (stacks)
	{
		moves = stacks->cost;
		if (stacks->median == stacks->target->median)
			moves -= 1;
		if (moves < best_score)
		{
			best_score = moves;
			best_node = stacks;
		}
		stacks = stacks->next;
	}
	return (best_node);
}
