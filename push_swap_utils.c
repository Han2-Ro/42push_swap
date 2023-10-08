/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:24:24 by hrother           #+#    #+#             */
/*   Updated: 2023/10/08 23:07:41 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	make_int_stack(char **str_arr, int size)
{
	t_stack	stack;
	int		i;

	stack.arr = malloc(size * sizeof(int));
	if (!stack.arr)
		return (stack);
	stack.size = size;
	stack.max_size = size;
	//TODO: check if input is valid
	i = 0;
	while (i < size)
	{
		stack.arr[size - 1 - i] = ft_atoi(str_arr[i]);
		i++;
	}
	return (stack);
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

int	count_ops(char *str, char c)
{
	int	res;

	if (!str)
		return (2147483647);
	res = 0;
	while (*str)
	{
		if (*str == c)
			res++;
		str++;
	}
	return (res);
}

int	init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**tmp;
	int		size;

	size = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[size])
			size++;
		*stack_a = make_int_stack(tmp, size);
		while (size--)
			free(tmp[size]);
		free(tmp);
	}
	else
		*stack_a = make_int_stack(argv + 1, argc - 1);
	if (!(stack_a->arr))
		return (1);
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	stack_b->arr = malloc(stack_b->max_size * sizeof(int));
	return (1);
}
