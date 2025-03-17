#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct push_swap_list
{
	long					dataarg;
	int						index;
	int						cost;
	bool					up_median;
	bool					lowercost;
	struct push_swap_list 	*node;
	struct push_swap_list 	*prev;
	struct push_swap_list 	*next;
}					t_stack;

// Manage errors and checking of information passed to stacks
void	ft_errors_free(t_stack **a);
int		ft_duplicates(t_stack *s, int nbr);
void	ft_free_stacks(t_stack **stacks);
int		ft_syntax(char *s);

//Order an list utils for stack
int		ft_lstlen_ps(t_stack *stacks);
int		ft_lstsize_ps(t_stack *lst);
t_stack	*ft_lstlast_ps(t_stack *lst);
bool	ft_stackorder(t_stack *stacks);
void	ft_stack_median(t_stack *stacks);

//MOvements
void	pa(t_stack **a,t_stack **b);
void	pb(t_stack **a,t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//Find numbers mas and min
t_stack	*ft_findmin(t_stack *stacks);
t_stack	*ft_findmax(t_stack *stacks);
t_stack	*ft_lowercost(t_stack *stacks);

//Initialize stac a to b
void	ft_set_a(t_stack *a, t_stack *b);
t_stack	*ft_set_b(t_stack *a, t_stack *b);
void	ft_pushcost(t_stack *a,t_stack *b,t_stack *node_a, int *counter);
t_stack	*ft_cheapest(t_stack **a, t_stack **b);

//Split for argv and initialize stacks
void	ft_join_node(t_stack **stacks, int n);
void	ft_stack_in(t_stack **args, char **argv);
char	**ft_split_ps(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

//Algorithm turk
void	ft_sort_three(t_stack **a);
void	ft_sort_pb(t_stack **a, t_stack **b);
void	ft_sort_pa(t_stack **a, t_stack **b);
void	ft_sort_stacks(t_stack **a, t_stack **b);
void	ft_revise_end(t_stack **a);
void	ft_stack_top_head(t_stack **a, t_stack **b, t_stack *min_cost);

#endif