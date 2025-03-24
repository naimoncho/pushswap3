#include "push_swap.h"

static long		ft_atol_ps(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str ++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		str ++;
	}
	return (num * sign);
}
void	ft_join_node(t_stack **stacks, char **nums, int *index)
{
	int		i;
	long	nb;
	t_stack	*node;

	nb = 0;
	if (!nums[1])
	{
		nb = ft_atol_ps(nums[0]);
		if (nb == (long)INT_MAX + 1)
			write(2, "Error\n", 6);
		node = ft_lstnew_ps((*index)++, nb);
		ft_lstadd_back_ps(stacks, node);
	}
	else
	{
		i = 0;
		while (nums[i])
		{
			nb = ft_atol_ps(nums[i++]);
			if (nb == (long)INT_MAX + 1)
				write(2, "Error\n", 6);
			node = ft_lstnew_ps((*index)++, nb);
			ft_lstadd_back_ps(stacks, node);
		}
	}
}

void	ft_stack_in(char **argv, t_stack **a)
{
	int		j;
	int		index;
	char	**nums;

	j = 0;
	index = 1;
	while (argv[j])
	{
		if (argv[j][0] != '\0')
		{
			nums = ft_split_ps(argv[j], ' ');
			ft_join_node(a, nums, &index);
			ft_duplicates(*a);
			ft_free_all(nums);
		}
		else
			write(2, "Error\n", 6);
		j ++;
	}
}