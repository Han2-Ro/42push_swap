/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:33 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:17:00 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->arr[stack->size - 1];
	stack->arr[stack->size - 1] = stack->arr[stack->size - 2];
	stack->arr[stack->size - 2] = tmp;
}

void	push(t_stack *src, t_stack *dst)
{
	if (src->size < 1)
		return ;
	if (dst->size >= dst->max_size)
		return ;
	src->size--;
	dst->arr[dst->size] = src->arr[src->size];
	dst->size++;
}

void	rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size <= 1)
		return ;
	i = stack->size - 1;
	tmp = stack->arr[i];
	while (--i >= 0)
		stack->arr[i + 1] = stack->arr[i];
	stack->arr[0] = tmp;
}

void	rev_rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size <= 1)
		return ;
	i = 1;
	tmp = stack->arr[0];
	while (i < stack->size)
	{
		stack->arr[i - 1] = stack->arr[i];
		i++;
	}
	stack->arr[stack->size - 1] = tmp;
}

void	exec_operation(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (operation[0] == 's')
	{
		if (operation[1] == 'a' || operation[1] == 's')
			swap(stack_a);
		if (operation[1] == 'b' || operation[1] == 's')
			swap(stack_b);
	}
	if (operation[0] == 'p')
	{
		if (operation[1] == 'a')
			push(stack_b, stack_a);
		else if (operation[1] == 'b')
			push(stack_a, stack_b);
	}
	if (operation[0] == 'r')
	{
		if (operation[1] == 'r')
		{
			if (operation[2] == 'a')
				return (rev_rotate(stack_a));
			if (operation[2] == 'b')
				return (rev_rotate(stack_b));
			if (operation[2] == 'r')
				return (rev_rotate(stack_a), rev_rotate(stack_b));
		}
		if (operation[1] == 'a' || operation[1] == 'r')
			rotate(stack_a);
		if (operation[1] == 'b' || operation[1] == 'r')
			rotate(stack_b);
	}
}

char	*exec_str(t_stack *stack_a, t_stack *stack_b, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		exec_operation(stack_a, stack_b, str + i);
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	return (str);
}

int check(t_stack stack, char *str)
{
	t_stack stack_a;
	t_stack stack_b;

	stack_a = stackdup(stack);
	stack_b.max_size = stack_a.max_size;
	stack_b.size = 0;
	stack_b.arr = malloc(stack_b.max_size * sizeof(int));
	exec_str(&stack_a, &stack_b, str);
	return (is_sorted(stack_a));
}
