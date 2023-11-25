/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:44:41 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 15:14:28 by hrother          ###   ########.fr       */
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
	int			i_dest;
	t_rotset	res;

	i_dest = index_to_insert(dest, src->arr[i_src], ascending);
	res.nra = src->size - i_src - 1;
	res.nrra = i_src + 1;
	res.nrb = dest->size - i_dest - 1;
	res.nrrb = i_dest + 1;
	return (cost(select_best_rot(res)));
}

int	find_next_nbr(t_stack *src, t_stack *dest, int ascending)
{
	int	i;
	int	best_i;
	int	best_val;
	int	current_val;

	best_val = 2147483647;
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
