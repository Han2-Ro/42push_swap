/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_brootforce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:13:13 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:18:05 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*shortes_solve(t_stack stack_a, t_stack stack_b, char *op, int limit)
{
	char	*op_arr[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int		i;
	char	*other_ret;
	char	*this_res;

	this_res = NULL;
	exec_operation(&stack_a, &stack_b, op);
	if (is_sorted(stack_a))
		return (free(stack_a.arr), free(stack_b.arr), ft_strdup(op));
	if (limit <= 0)
		return (free(stack_a.arr), free(stack_b.arr), NULL);
	i = 0;
	while (i < 11)
	{
		other_ret = shortes_solve(stackdup(stack_a), stackdup(stack_b), op_arr[i], limit - 1);
		if (count_ops(other_ret, '\n') < count_ops(this_res, '\n'))
		{
			free(this_res);
			this_res = other_ret;
		}
		else
			free(other_ret);
		i++;
	}
	free(stack_a.arr);
	free(stack_b.arr);
	if (this_res)
	{
		other_ret = ft_strjoin(op, this_res);
		return (free(this_res), other_ret);
	}
	else
		return (NULL);
}
