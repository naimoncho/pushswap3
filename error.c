#include "push_swap.h"

void	ft_errors_free(t_stack **a)
{
	ft_free_stacks(a);
	write(2, "Error\n", 6);
	exit(0);
}

int ft_syntax(char *s)
{
    int i = 0;

    if (s[i] == '+' || s[i] == '-')
        i++;
    if (s[i] == '\0')
        return (1);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (1);
        i++;
    }
    return (0);
}

void	ft_free_stacks(t_stack **stacks)
{
	t_stack	*current;
	t_stack	*temp;

	if (!stacks)
		return ;
	current = *stacks;
	while (current)
	{
		temp = current->next;
		current->dataarg = 0;
		free(current);
		current = temp;
	}
	*stacks = NULL;
}

int	ft_duplicates(t_stack *s, int nbr)
{
	if (!s)
		return (0);
	while (s)
	{
		if (s->dataarg == nbr)
			return (1);
		s = s->next;
	}
	return (0);
}
