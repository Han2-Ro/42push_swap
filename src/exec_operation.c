/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:59:33 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 14:05:51 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ret = operation[2] == '\n';
	if (operation[1] == 'a')
		return (rotate(stack_a), ret);
	if (operation[1] == 'b')
		return (rotate(stack_b), ret);
	if (operation[1] == 'r')
		return (rotate(stack_a), rotate(stack_b), ret);
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
