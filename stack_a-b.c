#include "push_swap.h"

t_stack	*ft_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*min_cost;
	int		counter;
	int		moves;
	
	node_a = *a;
	moves = INT_MAX;
	while (node_a)
	{
		ft_pushcost(*a, *b, node_a, &counter);
		if (counter == 0)
			return (node_a);
		if (counter < moves)
		{
			moves = counter;
			min_cost = node_a;
		}
		node_a = node_a->next;
	}
	return (min_cost);
}

void	ft_set_a(t_stack *a, t_stack *b)
{
	t_stack	*node_b;
	long	best_index;

	best_index = LONG_MIN;
	node_b = b;
	while (node_b)
	{
		if(node_b->dataarg < a->dataarg && node_b->dataarg > best_index)
		{
			best_index = node_b->dataarg;
			a->target = node_b;
		}
		node_b = node_b->next;
	}
	if (best_index == LONG_MIN)
		a->target = ft_findmax(b);
}

void	ft_pushcost(t_stack *a,t_stack *b,t_stack *node_a, int *counter)
{
	int	below_median;
	
	ft_set_a(node_a, b);
	if (!node_a || !node_a->target)
		return ;
	below_median = ft_lstlen_ps(b) - node_a->target->index;
	if (node_a->median)
		*counter = node_a->index;
	else
		*counter = ft_lstlen_ps(a) - node_a->index;
	if (node_a->median && node_a->target->median)
	{
		if (node_a->target->index > *counter)
			counter += (node_a->target->index - *counter);
	}
	else if (!node_a->median && !node_a->target->median)
	{
		if (*counter < below_median)
			counter += (below_median - *counter);
	}
	else if (node_a->target->median)
		*counter += node_a->target->index;
	else
		*counter += below_median;
}

t_stack	*ft_set_b(t_stack *node, t_stack *a)
{
	t_stack	*target;
	long	best_index;
	
	best_index = LONG_MAX;
	target = a;
	while (target)
	{
		if(target->dataarg > node->dataarg && target->dataarg < best_index)
		{
			best_index = target->dataarg;
			node->target = target;
		}
		target = target->next;
	}
	if (best_index == LONG_MAX)
		node->target = ft_findmin(a);
	return (node->target);
}

void	ft_stack_top_head(t_stack **a, t_stack **b, t_stack *min_cost)
{
	if (!min_cost || !min_cost->target)
		return ;
	if (min_cost->median && min_cost->target->median)
		while (*a != min_cost && *b != min_cost->target)
			ft_rotate(a, b, MOVERR);
	else if (!min_cost->median && !min_cost->target->median)
		while (*a != min_cost && *b != min_cost->target)
			ft_rever_rotate(a, b, MOVERRR);
	if (min_cost->median)
		while (*a != min_cost)
			ft_rotate(a, b, MOVERA);
	else	
		while (*a != min_cost)
			ft_rever_rotate(a, b, MOVERRA);
	if (min_cost->target->median)
		while (*b != min_cost->target)
			ft_rotate(a, b, MOVERB);
	else
		while (*b != min_cost->target)
			ft_rever_rotate(a, b, MOVERRB);
}

// static void	ft_analyse(t_stack *a, t_stack *b)
// {
// 	int	count1;
// 	int	count2;
// 	t_stack *current_a;

// 	count1 = ft_lstlen_ps(a);
// 	count2 = ft_lstlen_ps(b);
// 	current_a = a;
// 	while (current_a)
// 	{
// 		if (!current_a->node)
// 		{
// 			current_a = current_a->next;
// 			continue ;
// 		}
// 		current_a->cost = current_a->index;
// 		if (!(current_a->up_median))
// 			current_a->cost = count1 - current_a->index;
// 		if (current_a->node->up_median)
// 			current_a->cost += current_a->node->index;
// 		else
// 		current_a->cost += count2 - current_a->node->index;
// 		current_a = current_a->next;
// 	}
// }
// void	ft_index(t_stack *stacks)
// {
	// 	int	i;
// 	int	med;

// 	i = 0;
// 	if (!stacks)
// 		return ;
// 	med = ft_lstlen_ps(stacks) / 2;
// 	while (stacks)
// 	{
// 		stacks->index = i;
// 		if (i <= med)
// 			stacks->up_median = true;
// 		else
// 			stacks->up_median = false;
// 		stacks = stacks->next;
// 		i ++;
// 	}
// }
// void	ft_init_nodesa(t_stack *a, t_stack *b)
// {
	// 	if (!a || !b)
	// 		return ;
// 	ft_index(a);
// 	ft_index(b);
// 	ft_set_a(a, b);
// 	ft_analyse(a, b);
// 	ft_cheapest(a);
// }
