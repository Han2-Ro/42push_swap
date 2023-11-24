/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:11:33 by hrother           #+#    #+#             */
/*   Updated: 2023/11/24 23:09:53 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_is_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_strlen(str) <= 9)
		return (1);
	while (*str == '+' || *str == '0')
		str++;
	if (ft_strncmp(ft_itoa(ft_atoi(str)), str, 11) != 0)
		return (0);
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < i)
		{
			if (stack->arr[i] == stack->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_stack(t_stack *stack, char **str_arr, int size)
{
	int		i;

	stack->arr = malloc(size * sizeof(int));
	if (!stack->arr)
		return (0);
	stack->size = size;
	stack->max_size = size;
	i = 0;
	while (i < size)
	{
		if (!check_is_int(str_arr[i]))
			return (free(stack->arr), stack->arr = NULL, 0);
		stack->arr[size - 1 - i] = ft_atoi(str_arr[i]);
		i++;
	}
	if (!check_duplicates(stack))
		return (free(stack->arr), stack->arr = NULL, 0);
	return (1);
}

int	init_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**tmp;
	int		size;

	size = 0;
	if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		if (!tmp)
			error("ERROR: malloc failed", NULL, NULL);
		while (tmp[size])
			size++;
		fill_stack(stack_a, tmp, size);
		while (size--)
			free(tmp[size]);
		free(tmp);
	}
	else
		fill_stack(stack_a, argv + 1, argc - 1);
	stack_b->max_size = stack_a->max_size;
	stack_b->size = 0;
	stack_b->arr = malloc(stack_b->max_size * sizeof(int));
	if (!(stack_a->arr && stack_b->arr))
		error("ERROR: Invalid Input", stack_a, stack_b);
	return (1);
}
