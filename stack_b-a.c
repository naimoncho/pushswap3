#include "push_swap.h"

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
