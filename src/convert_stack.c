/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:26:03 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:20:42 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	convert_stack(t_stack *stack)
{
	t_stack	sorted_stack;
	int		i;
	int		j;

	sorted_stack = stackdup(*stack);
	quick_sort(sorted_stack.arr, 0, stack->size - 1);
	//print_stack(sorted_stack);
	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (stack->arr[i] != sorted_stack.arr[j])
			j++;
		stack->arr[i] = j;
		i++;
	}
	free(sorted_stack.arr);
}
