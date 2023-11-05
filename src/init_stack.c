/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:11:33 by hrother           #+#    #+#             */
/*   Updated: 2023/11/05 23:12:47 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-'))
			return (0);
		i++;
	}
	//TODO: check for overflow
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
	//TODO: check if input is valid
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
