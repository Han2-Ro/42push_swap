/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:24:24 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 15:26:50 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	wa_array(int i, t_stack *stack)
{
	int	res;

	if (stack->size <= 0)
		return (0);
	res = (i + stack->offset) % stack->size;
	if (res >= 0)
		return (res);
	else
		return (stack->size + res);
}

void	error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	(void)msg;
	if (stack_a)
		free(stack_a->arr);
	if (stack_b)
		free(stack_b->arr);
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	update_offset(t_stack *stack, int ascending)
{
	int	offset;
	int	value;
	int	i;

	if (ascending)
		value = -2147483648;
	else
		value = 2147483647;
	i = 0;
	while (i < stack->size)
	{
		if ((ascending && stack->arr[i] >= value)
			|| (!ascending && stack->arr[i] <= value))
		{
			value = stack->arr[i];
			offset = i;
		}
		i++;
	}
	stack->offset = offset;
}

int	is_sorted(t_stack stack)
{
	int	i;
	int	result;

	if (stack.size != stack.max_size)
		return (0);
	i = 1;
	result = 1;
	while (i < stack.size)
	{
		result &= stack.arr[i - 1] >= stack.arr[i];
		i++;
	}
	return (result);
}
