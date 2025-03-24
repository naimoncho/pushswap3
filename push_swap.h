#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include "moves.h"
#include "./libft/libft.h"

typedef struct push_swap_list
{
	long					dataarg;
	int						index;
	int						cost;
	bool					median;
	bool					lowercost;
	struct push_swap_list 	*target;
	struct push_swap_list 	*prev;
	struct push_swap_list 	*next;
}					t_stack;

// Manage errors and checking of information passed to stacks
void	ft_duplicates(t_stack *s);
void	ft_free_stacks(t_stack **stacks);
void	ft_free_all(char **matrix);
int		ft_putstr(char *s);
int		ft_putchar(int c);

//Order an list utils for stack
int		ft_lstlen_ps(t_stack *stacks);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_ps(int index, long num);
t_stack	*ft_lstlast_ps(t_stack *lst);
int		ft_stackorder(t_stack *stacks);
void	ft_stack_median(t_stack *stacks);

//MOvements
void	ft_rever_rotatenode(t_stack **stacks);
void	ft_rever_rotate(t_stack **a,t_stack **b, int move);
void	ft_pushnode(t_stack **dest, t_stack **src);
void	ft_push(t_stack **a,t_stack **b, int move);
void	ft_rotatenode(t_stack **stacks);
void	ft_rotate(t_stack **a,t_stack **b, int move);
void	ft_swapnode(t_stack **top);
void	ft_swap(t_stack **a,t_stack **b, int move);

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
void	ft_join_node(t_stack **stacks, char **nums, int *index);
void	ft_stack_in(char **argv, t_stack **a);
char	**ft_split_ps(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);

//Algorithm turk
void	ft_sort_three(t_stack **a);
void	ft_sort_pb(t_stack **a, t_stack **b);
void	ft_sort_pa(t_stack **a, t_stack **b);
void	ft_sort_stacks(t_stack **a, t_stack **b);
void	ft_revise_end(t_stack **a, t_stack **b);
void	ft_stack_top_head(t_stack **a, t_stack **b, t_stack *min_cost);

#endif