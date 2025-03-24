#include "push_swap.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	a = ft_calloc(1, sizeof(t_stack *));
	b = ft_calloc(1, sizeof(t_stack *));
	if (argc > 1)
	{
		ft_stack_in(argv, a);
		if (!ft_stackorder(*a))
		{
			if (ft_lstlen_ps(*a) == 2)
				ft_swap(a, b, MOVESA);
			else if (ft_lstlen_ps(*a) == 3)
				ft_sort_three(a);
			else
				ft_sort_stacks(a, b);
		}
		ft_free_stacks(a);
		ft_free_stacks(b);
	}
	else
		write (2, "Error\n", 6);
		exit(EXIT_SUCCESS);
}
