/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:36 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:43:49 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	print_stack(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size)
	{
		ft_printf("%d, ", stack. arr[i]);
		i++;
	}
	ft_printf("\b\b size:%d max_size:%d offset: %d\n", stack.size, stack.max_size, stack.offset);
}

void	test_index_to_insert(t_stack *stack_a)
{
	int index;
	print_stack(*stack_a);
	ft_printf("wa(-1):%d\n", wa_array(-1, stack_a));
	index = index_to_insert(stack_a, 5, 1);
	ft_printf("index: %d\n", index);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*solution;

	//TODO: check input: numbres out of int range
	//TODO: fix memory leaks
	//TODO: memory protection
	//TODO: optimize runtime
	//TODO: norminette
	init_stacks(argc, argv, &stack_a, &stack_b);
	update_offset(&stack_a, 1);
	solution = calculate_solution(&stack_a, &stack_b);
	ft_printf("%s", solution);
	free(solution);
	free(stack_a.arr);
	free(stack_b.arr);
}
