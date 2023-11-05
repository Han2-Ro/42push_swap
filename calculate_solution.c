/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:51:11 by hannes            #+#    #+#             */
/*   Updated: 2023/11/05 18:19:59 by hrother          ###   ########.fr       */
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

int	index_to_insert(t_stack *stack, int val, int ascending)
{
	int	i;
	int	result;
	int	val_res;

	result = 0;
	if (ascending)
		val_res = 2147483647;
	else
		val_res = -2147483648;
	i = 0;
	while (i < stack->size)
	{
		if ((!ascending && stack->arr[i] > val_res)
			|| (ascending && stack->arr[i] < val_res))
		{
			val_res = stack->arr[i];
			result = i;
		}
		i++;
	}
	if (ascending)
		val_res = 2147483647;
	else
		val_res = -2147483648;
	i = 0;
	while (i < stack->size)
	{
		if ((!ascending && stack->arr[i] < val && stack->arr[i] > val_res)
			|| (ascending && stack->arr[i] > val && stack->arr[i] < val_res))
		{
			val_res = stack->arr[i];
			result = i;
		}
		i++;
	}
	return (result);
}

int	count_rotates(t_stack *src, t_stack *dest, int i_src, int ascending)
{
	int	i_dest;
	int	opts[4];

	i_dest = index_to_insert(dest, src->arr[i_src], ascending);
	opts[0] = max(i_src, i_dest) + 1;
	opts[1] = max(src->size - i_src, dest->size - i_dest) - 1;
	opts[2] = i_src + dest->size - i_dest;
	opts[3] = src->size - i_src + i_dest;
	return (min(min(opts[0], opts[1]), min(opts[2], opts[3])));
}

int	find_next_nbr(t_stack *src, t_stack *dest, int ascending)
{
	int	i;
	int	best_i;
	int	best_val;

	best_val = 2147483647; //TODO: max int
	i = 0;
	while (i < src->size)
	{
		if (count_rotates(src, dest, i, ascending) < best_val)
		{
			best_i = i;
			best_val = count_rotates(src, dest, i, ascending);
		}
		i++;
	}
	return (best_i);
}

char	*push_next_nbr(t_stack *src, t_stack *dest, int ascending)
{
	char	*result;
	char	*tmp;
	int		i_src;
	int		i_dest;

	result = emptystr();
	tmp = emptystr();
	i_src = find_next_nbr(src, dest, ascending);
	i_dest = index_to_insert(dest, src->arr[i_src], ascending);
	ft_strattach(&result, "rra\n", i_src + 1);
	ft_strattach(&result, "rb\n", dest->size - i_dest - 1);
	ft_strattach(&tmp, "ra\n", src->size - i_src - 1);
	ft_strattach(&tmp, "rrb\n", i_dest + 1);
	if (count_ops(tmp) < count_ops(result))
	{
		free(result);
		result = tmp;
	}
	else
		free(tmp);
	tmp = emptystr();
	ft_strattach(&tmp, "rrr\n", min(i_src, i_dest) + 1);
	if (i_src > i_dest)
		ft_strattach(&tmp, "rra\n", i_src - i_dest);
	else
		ft_strattach(&tmp, "rrb\n", i_dest - i_src);
	if (count_ops(tmp) < count_ops(result))
	{
		free(result);
		result = tmp;
	}
	else
		free(tmp);
	tmp = emptystr();
	ft_strattach(&tmp, "rr\n", min(src->size - i_src, dest->size - i_dest) - 1);
	if (src->size - i_src > dest->size - i_dest)
		ft_strattach(&tmp, "ra\n", (src->size - i_src) - (dest->size - i_dest));
	else
		ft_strattach(&tmp, "rb\n", (dest->size - i_dest) - (src->size - i_src));
	if (count_ops(tmp) < count_ops(result))
	{
		free(result);
		result = tmp;
	}
	else
		free(tmp);
	ft_strattach(&result, "pb\n", 1);
	exec_str(src, dest, result);
	return (result);
}

char	*final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min_i;
	int		min_val;
	char	*result;

	result = emptystr();
	i = 0;
	min_val = 2147483647;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < min_val)
		{
			min_i = i;
			min_val = stack_a->arr[i];
		}
		i++;
	}
	if (min_i + 1 < stack_a->size - min_i - 1)
		ft_strattach(&result, "rra\n", min_i + 1);
	else
		ft_strattach(&result, "ra\n", stack_a->size - min_i -1);
	return (exec_str(stack_a, stack_b, result));
}

char	*calculate_solution(t_stack *stack_a, t_stack *stack_b)
{
	char	*result;
	char	*ops;

	result = malloc(sizeof(char));
	result[0] = '\0';
	ft_strattach(&result, exec_str(stack_a, stack_b, "pb\npb\n"), 1);
	while (stack_a->size > 2)
	{
		ops = push_next_nbr(stack_a, stack_b, 0);
		ft_strattach(&result, ops, 1);
		free(ops);
	}
	//ft_strattach(&result, solve_3stack(stack_a, stack_b));
	while (stack_b->size > 0)
	{
		//ft_strattach(&result, exec_str(stack_a, stack_b, "pa\n"), 1);
		ops = push_next_nbr(stack_b, stack_a, 1);
		ft_strattach(&result, swap_stacks(ops), 1);
		free(ops);
	}
	ops = final_rotate(stack_a, stack_b);
	ft_strattach(&result, ops, 1);
	free(ops);
	return (result);
}
