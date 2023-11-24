/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:44:41 by hrother           #+#    #+#             */
/*   Updated: 2023/11/24 22:55:31 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	index_to_insert(t_stack *stack, int val, int ascending)
{
	int	bottom;
	int	mid;
	int	top;

	if (stack->size <= 0)
		return (0);
	(void) ascending;
	bottom = 0;
	top = stack->size - 1;
	if ((ascending && val < stack->arr[wa_array(top, stack)])
		|| (!ascending && val > stack->arr[wa_array(top, stack)]))
		return (wa_array(top, stack));
	if ((ascending && val > stack->arr[wa_array(bottom, stack)])
		|| (!ascending && val < stack->arr[wa_array(bottom, stack)]))
		return (wa_array(top, stack));
	while (bottom + 1 < top)
	{
		mid = (bottom + top) / 2;
		if ((ascending && val > stack->arr[wa_array(mid, stack)])
			|| (!ascending && val < stack->arr[wa_array(mid, stack)]))
			top = mid;
		else
			bottom = mid;
	}
	return (wa_array(bottom, stack));
}

int	count_rotates(t_stack *src, t_stack *dest, int i_src, int ascending)
{
	int	i_dest;
	int	opts[4];

	i_dest = index_to_insert(dest, src->arr[i_src], ascending);
	opts[0] = max(i_src, i_dest) + 1;
	opts[1] = max(src->size - i_src, dest->size - i_dest) - 1;
	opts[2] = i_src + dest->size - i_dest;
	opts[3] = src->size - i_src + i_dest;
	return (min(min(opts[0], opts[1]), min(opts[2], opts[3])));
}

int	find_next_nbr(t_stack *src, t_stack *dest, int ascending)
{
	int	i;
	int	best_i;
	int	best_val;
	int	current_val;

	best_val = 2147483647; //TODO: max int
	i = 0;
	while (i < src->size)
	{
		current_val = count_rotates(src, dest, i, ascending);
		if (current_val < best_val)
		{
			best_i = i;
			best_val = current_val;
		}
		i++;
	}
	return (best_i);
}
