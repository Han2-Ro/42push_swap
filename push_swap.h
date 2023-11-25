/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:14:43 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 13:39:51 by hrother          ###   ########.fr       */
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
	int offset;
}	t_stack;

typedef struct s_rotate
{
	int nra;
	int nrra;
	int nrb;
	int nrrb;
}	t_rotate;

/*void	push(t_stack *src, t_stack *dst);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);
void	exec_operation(t_stack *stack_a, t_stack *stack_b, char *operation);*/
char		*exec_str(t_stack *stack_a, t_stack *stack_b, char *str);
void		update_offset(t_stack *stack, int ascending);
int			is_sorted(t_stack stack);
int			init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void		quick_sort(int *arr, int start, int end);
void		solve(t_stack *stack_a, t_stack *stack_b);
char		*ft_strattach(char **str, char *to_attach, int repeats);
char		*emptystr(void);
int			min(int a, int b);
int			max(int a, int b);
void		ft_swap(int *a, int *b);
int			wa_array(int i, t_stack *stack);
void		error(char *msg, t_stack *stack_a, t_stack *stack_b);
void		debug(char *msg);
t_rotate	generate_rot(t_stack *src, t_stack *dest, int ascending);
t_rotate	init_rotates(int nra, int nrra, int nrb, int nrrb);

int			index_to_insert(t_stack *stack, int val, int ascending);
int			find_next_nbr(t_stack *src, t_stack *dest, int ascending);

#endif