/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:36 by hrother           #+#    #+#             */
/*   Updated: 2023/10/07 15:03:25 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	make_int_stack(char **str_arr, int size)
{
	t_stack	stack;

	stack.arr = malloc(size * sizeof(int));
	if (!stack.arr)
		return (stack);
	stack.size = size;
	stack.max_size = size;
	//TODO: check if input is valid
	while (size-- > 0)
	{
		stack.arr[size] = ft_atoi(str_arr[size]);
	}
	return (stack);
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
		result &= stack.arr[i - 1] <= stack.arr[i];
		i++;
	}
	return (result);
}

void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		ft_printf("%d, ", stack. arr[i]);
		i++;
	}
	ft_printf("\b\b size:%d max_size:%d\n", stack.size, stack.max_size);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack = make_int_stack(argv + 1, argc - 1);
	if (!(stack.arr))
		return (1);
	print_stack(stack);
}
