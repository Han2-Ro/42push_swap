/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/11/04 18:33:03 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*swap_stacks(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			str[i] = 'b';
		else if (str[i] == 'b')
			str[i] = 'a';
		i++;
	}
	return (str);
}

char *solve_3stack(t_stack *stack_a, t_stack *stack_b) //TODO: for all nbrs
{
	char	*str;

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
	int	result;
	int	val_res;

	result = 0;
	val_res = -2147483647;
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] > val_res)
		{
			val_res = stack->arr[i];
			result = i;
		}
		i++;
	}
	val_res = -2147483647;
	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < val && stack->arr[i] > val_res)
		{
			val_res = stack->arr[i];
			result = i;
		}
		i++;
	}
	return (result);
}

int	count_rotates(t_stack *src, t_stack *dest, int i_src)
{
	int	i_dest;
	int	opts[4];

	i_dest = index_to_insert(dest, src->arr[i_src]);
	opts[0] = max(i_src, i_dest) + 1;
	opts[1] = max(src->size - i_src, dest->size - i_dest) - 1;
	opts[2] = i_src + dest->size - i_dest;
	opts[3] = src->size - i_src + i_dest;
	return (min(min(opts[0], opts[1]), min(opts[2], opts[3])));
}

int	find_next_nbr(t_stack *src, t_stack *dest)
{
	int	i;
	int	best_i;
	int	best_val;

	best_val = 2147483647; //TODO: max int
	i = 0;
	while (i < src->size)
	{
		if (count_rotates(src, dest, i) < best_val)
		{
			best_i = i;
			best_val = count_rotates(src, dest, i);
		}
		i++;
	}
	return (best_i);
}

char	*push_next_nbr(t_stack *src, t_stack *dest)
{
	char	*result;
	char	*tmp;
	int		i_src;
	int		i_dest;

	(void) tmp;
	result = emptystr();
	i_src = find_next_nbr(src, dest);
	i_dest = index_to_insert(dest, src->arr[i_src]);
	ft_strattach(&result, "rra\n", i_src + 1);
	ft_strattach(&result, "rb\n", dest->size - i_dest + 1);
	//TODO: work
	return (result);
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
	while (max_i-- >= 0)
	{
		ft_strattach(&result, exec_str(stack_a, stack_b, "rrb\n"), 1);
	}
	return (result);
}

char	*calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
	char	*result;
	char	*ops;

	result = malloc(sizeof(char));
	result[0] = '\0';
	ft_strattach(&result, exec_str(stack_a, stack_b, "pb\npb\n"), 1);
	while (stack_a->size > 0)
	{
		ops = push_next_nbr(stack_a, stack_b);
		ft_strattach(&result, ops, 1);
		free(ops);
	}
	//ft_strattach(&result, solve_3stack(stack_a, stack_b));
	while (stack_b->size > 0)
	{
		ft_strattach(&result, exec_str(stack_a, stack_b, "pa\n"), 1);
	}
	ops = rotate_b(stack_a, stack_b);
	ft_strattach(&result, ops, 1);
	free(ops);
	return (result);
}
