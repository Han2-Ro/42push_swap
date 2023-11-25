/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:14:43 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 14:48:14 by hrother          ###   ########.fr       */
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

typedef struct s_rotset
{
	int nra;
	int nrra;
	int nrb;
	int nrrb;
}	t_rotset;

char		*exec_str(t_stack *stack_a, t_stack *stack_b, char *str);
void		update_offset(t_stack *stack, int ascending);
int			is_sorted(t_stack stack);
int			init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
void		push_next_nbr(t_stack *src, t_stack *dest, int btoa);
void		solve(t_stack *stack_a, t_stack *stack_b);
void		ft_swap(int *a, int *b);
int			wa_array(int i, t_stack *stack);
void		error(char *msg, t_stack *stack_a, t_stack *stack_b);

t_rotset	init_rotates(int nra, int nrra, int nrb, int nrrb);
int			cost(t_rotset rot);
t_rotset	select_best_rot(t_rotset rot);
t_rotset	generate_rot(t_stack *src, t_stack *dest, int ascending);
void		exec_rotset(t_stack *stack_a, t_stack *stack_b, t_rotset rotate);

void		swap(t_stack *stack);
void		push(t_stack *src, t_stack *dst);
void		rotate(t_stack *stack);
void		rev_rotate(t_stack *stack);

int			index_to_insert(t_stack *stack, int val, int ascending);
int			find_next_nbr(t_stack *src, t_stack *dest, int ascending);

#endif