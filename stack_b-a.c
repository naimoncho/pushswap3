#include "push_swap.h"

t_stack	*ft_set_b(t_stack *a, t_stack *b)
{
	t_stack	*node_a;
	long	best_index;
	
	best_index = LONG_MAX;
	node_a = a;
	while (node_a)
	{
		if(node_a->dataarg < b->dataarg && node_a->dataarg > best_index)
		{
			best_index = node_a->dataarg;
			b->node = node_a;
		}
		node_a = node_a->next;
	}
	if (best_index == LONG_MAX)
		b->node = ft_findmax(a);
	if (!b->node)
		return (NULL);
	return (b->node);
}

void	ft_stack_top_head(t_stack **a, t_stack **b, t_stack *min_cost)
{
	if (!min_cost || !min_cost->node)
		return;
	if (min_cost->up_median && min_cost->node->up_median)
		while (*a != min_cost && *b != min_cost->node)
			rr(a,b);
	else if (!min_cost->up_median && !min_cost->node->up_median)
		while (*a != min_cost && *b != min_cost->node)
			rrr(a,b);
	while (*a != min_cost)
	{
		if (min_cost->up_median)
			ra(a);
		else	
			rra(a);
	}
	while (*b != min_cost->node)
	{
		if (min_cost->node->up_median)
			rb(b);
		else
			rrb(b);
	}
}

// void	ft_init_nodesb(t_stack *a, t_stack *b)
// {
// 	ft_index(a);
// 	ft_index(b);
// 	ft_set_b(a, b);
// }
// static void ft_sort_array(int *arr, int size)
// {
// 	int i;
// 	int j;
// 	int temp;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = 0;
// 		while (j < size - i - 1)
// 		{
// 			if (arr[j] > arr[j + 1])
// 			{
// 				temp = arr[j];
// 				arr[j] = arr[j + 1];
// 				arr[j + 1] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
// int ft_find_median(t_stack *a)
// {
// 	int		i;
// 	int		size;
// 	int		*values;
// 	t_stack	*temp;

// 	if (!a)
// 		return 0;
// 	size = ft_lstlen_ps(a);
// 	values = malloc(sizeof(int) * size);
// 	if (!values)
// 		return 0;
// 	i = 0;
// 	temp = a;
// 	while (temp)
// 	{
// 		values[i] = temp->dataarg;
// 		temp = temp->next;
// 		i++;
// 	}
// 	ft_sort_array(values, size);
// 	int median = values[size / 2];
// 	free(values);
// 	return median;
// }
