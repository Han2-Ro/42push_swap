/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:24:24 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:58:06 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	error(char *msg, t_stack *stack_a, t_stack *stack_b)
{
	(void)msg;
	free(stack_a->arr);
	free(stack_b->arr);
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_stack	stackdup(t_stack stack)
{
	t_stack	dup;
	int		i;

	dup.max_size = stack.max_size;
	dup.size = stack.size;
	dup.arr = malloc(dup.max_size * sizeof(int));
	i = 0;
	while (i < dup.size)
	{
		dup.arr[i] = stack.arr[i];
		i++;
	}
	return (dup);
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
