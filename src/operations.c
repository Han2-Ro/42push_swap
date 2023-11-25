/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:01:56 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 14:02:53 by hrother          ###   ########.fr       */
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
