/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/11/03 00:23:08 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *solve_3stack(t_stack *stack_a, t_stack *stack_b)
{
	char *str;

	str = "";
	if (stack_a->arr[0] == 0)
		str = exec_str(stack_a, stack_b, "");
	else if (stack_a->arr[1] == 0)
		str = exec_str(stack_a, stack_b, "rra\n");
	else if (stack_a->arr[2] == 0)
		str = exec_str(stack_a, stack_b, "ra\n");
	if (stack_a->arr[1] != 1)
		str = ft_strjoin(str, exec_str(stack_a, stack_b, "sa\n"));
	return (str);
}

int	index_to_insert(t_stack *stack, int val)
{
	int	i;

	i = 0;
	while (i < stack->size && stack->arr[i] > val)
		i++;
	while (i < stack->size && stack->arr[i] < val)
		i++;
	if (stack->arr[i - 1] < val)
	{
		while (i < stack->size && stack->arr[i - 1] < stack->arr[i])
			i++;
	}
	return (i - 1);
}

/*int	index_to_insert(t_stack *stack, int val)
{
	int	i;
	int	offset;

	offset = 1;
	while (offset < stack->size && stack->arr[offset - 1] < stack->arr[offset])
		offset++;
	i = 0;
	while (i < stack->size)
	{
		if (i + offset >= stack->size)
			offset -= stack->size;
		if (stack->arr[i + offset] > val)
			return (i + offset - 1);
	}
}*/

int	n_ops_to_pb(t_stack *stack_a, t_stack *stack_b, int i_a)
{
	int	i_b;
	int	result;

//TODO: compare all sums
	if (i_a < stack_a->size / 2)
		result = i_a + 1;
	else
		result = stack_a->size - i_a - 1;
	i_b = index_to_insert(stack_b, stack_a->arr[i_a]);
	if (i_b < stack_a->size / 2)
		result += i_b + 1;
	else
		result += stack_b->size - i_b - 1;
	return (result);
}

char	*push_nbr_b(t_stack *stack_a, t_stack *stack_b, int i_a)
{
	int		i_b;
	int		ra = 0;
	int		rra = 0;
	int		rb = 0;
	int		rrb = 0;
	char	*result;

	result = malloc(sizeof(char));
	result[0] = '\0';
	if (i_a < stack_a->size / 2)
		rra = (i_a + 1);
	else
		ra = stack_a->size - i_a - 1;
	i_b = index_to_insert(stack_b, stack_a->arr[i_a]);
	if (i_b < stack_a->size / 2)
		rrb = (i_b + 1);
	else
		rb = stack_b->size - i_b - 1;
	while (ra--)
		ft_strattach(&result, exec_str(stack_a, stack_b, "ra\n"));
	while (rra--)
		ft_strattach(&result, exec_str(stack_a, stack_b, "rra\n"));
	while (rb--)
		ft_strattach(&result, exec_str(stack_a, stack_b, "rb\n"));
	while (rrb--)
		ft_strattach(&result, exec_str(stack_a, stack_b, "rrb\n"));
	ft_strattach(&result, exec_str(stack_a, stack_b, "pb\n"));
	return (result);
}

int	find_next_nbr_to_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	best_i;
	int	best_val;

	best_val = 2147483647; //TODO: max int
	i = 0;
	while (i < stack_a->size)
	{
		if (n_ops_to_pb(stack_a, stack_b, i) < best_val)
		{
			best_i = i;
			best_val = n_ops_to_pb(stack_a, stack_b, i);
		}
		i++;
	}
	return (best_i);
}

char	*rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_i;
	int	max_val;
	char *result;

	result = malloc(sizeof(char));
	result[0] = '\0';
	i = 0;
	max_val = -2147483647;
	while (i < stack_b->size)
	{
		if (stack_b->arr[i] > max_val)
		{
			max_i = i;
			max_val = stack_b->arr[i];
		}
		i++;
	}
	while (max_i--)
	{
		ft_strattach(&result, exec_str(stack_a, stack_b, "rrb\n"));
	}
	return (result);
}

char	*calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
	char	*result;

	result = malloc(sizeof(char));
	result[0] = '\0';
	ft_strattach(&result, exec_str(stack_a, stack_b, "pb\npb\n"));
	while (stack_a->size > 3)
	{
		ft_strattach(&result, push_nbr_b(stack_a, stack_b, find_next_nbr_to_pb(stack_a, stack_b)));
	}
	ft_strattach(&result, solve_3stack(stack_a, stack_b));
	ft_strattach(&result, rotate_b(stack_a, stack_b));
	while (stack_b->size > 0)
	{
		ft_strattach(&result, exec_str(stack_a, stack_b, "pa\n"));
	}
	return (result);
}
