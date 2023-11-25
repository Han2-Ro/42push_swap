/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:33 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 13:24:04 by hrother          ###   ########.fr       */
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

static int	exec_rotate(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	int	ret;

	if (operation[1] == 'r')
	{
		ret = operation[3] == '\n';
		if (operation[2] == 'a')
			return (rev_rotate(stack_a), ret);
		if (operation[2] == 'b')
			return (rev_rotate(stack_b), ret);
		if (operation[2] == 'r')
			return (rev_rotate(stack_a), rev_rotate(stack_b), ret);
	}
	else
	{
		ret = operation[2] == '\n';
		if (operation[1] == 'a')
			return (rotate(stack_a), ret);
		if (operation[1] == 'b')
			return (rotate(stack_b), ret);
		if (operation[2] == 'r')
			return (rotate(stack_a), rotate(stack_b), ret);
	}
	return (0);
}

int	exec_operation(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	int	ret;

	ret = operation[2] == '\n';
	if (operation[0] == 's')
	{
		if (operation[1] == 'a')
			return (swap(stack_a), ret);
		if (operation[1] == 'b')
			return (swap(stack_b), ret);
		if (operation[1] == 's')
			return (swap(stack_a), swap(stack_b), ret);
	}
	if (operation[0] == 'p')
	{
		if (operation[1] == 'a')
			return (push(stack_b, stack_a), ret);
		else if (operation[1] == 'b')
			return (push(stack_a, stack_b), ret);
	}
	if (operation[0] == 'r')
		return (exec_rotate(stack_a, stack_b, operation));
	return (0);
}

char	*exec_str(t_stack *stack_a, t_stack *stack_b, char *str)
{
	int	i;

	if (!str)
		return (str);
	i = 0;
	while (str[i])
	{
		if (!exec_operation(stack_a, stack_b, str + i))
			return (0);
		while (str[i] && str[i] != '\n')
			i++;
		i++;
	}
	return (str);
}
