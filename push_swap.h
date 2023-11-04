/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:14:43 by hrother           #+#    #+#             */
/*   Updated: 2023/11/04 18:33:28 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	max_size;
}	t_stack;

void	exec_operation(t_stack *stack_a, t_stack *stack_b, char *operation);
void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
char	*exec_str(t_stack *stack_a, t_stack *stack_b, char *str);
int		fill_stack(t_stack *stack, char **str_arr, int size);
t_stack	stackdup(t_stack stack);
int		is_sorted(t_stack stack);
int		check(t_stack stack, char *str);
int		count_ops(char *str, char c);
char	*shortes_solve(t_stack stack_a, t_stack stack_b, char *str, int limit);
int		init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void	quick_sort(int *arr, int start, int end);
void	convert_stack(t_stack *stack);
void	print_stack(t_stack stack);
char	*calculate_solution(t_stack *stack_a, t_stack *stack_b);
char	*ft_strattach(char **str, char *to_attach, int repeats);
int		index_to_insert(t_stack *stack, int val);
char	*emptystr(void);

#endif