/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:36 by hrother           #+#    #+#             */
/*   Updated: 2023/11/20 21:21:29 by hrother          ###   ########.fr       */
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

/*
void	test_index_to_insert(t_stack *stack_a)
{
	int index_old;
	int	index_new;
	print_stack(*stack_a);
	index_old = index_to_insert(stack_a, 5, 0);
	index_new = index_to_insert_new(stack_a, 5, 0);
	ft_printf("old: %d, new: %d\n", index_old, index_new);
}
*/

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	//char	*solution;

	//TODO: check input: numbres out of int range
	//TODO: fix memory leaks
	//TODO: memory protection
	//TODO: optimize runtime
	//TODO: norminette
	init_stacks(argc, argv, &stack_a, &stack_b);
	update_offset(&stack_a, 0);
	//test_index_to_insert(&stack_a);
	calculate_solution(&stack_a, &stack_b);
	//ft_printf("%s", solution);
	//free(solution);
	free(stack_a.arr);
	free(stack_b.arr);
}
