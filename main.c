/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:36 by hrother           #+#    #+#             */
/*   Updated: 2023/11/04 18:11:59 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void	exec_example(t_stack stack_a, t_stack stack_b)
{
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("sorted:%d\n", is_sorted(stack_a));
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "sa");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "pb");
	exec_operation(&stack_a, &stack_b, "pb");
	exec_operation(&stack_a, &stack_b, "pb");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "rr");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "rrr");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "sa");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	exec_operation(&stack_a, &stack_b, "pa");
	exec_operation(&stack_a, &stack_b, "pa");
	exec_operation(&stack_a, &stack_b, "pa");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");
	ft_printf("sorted:%d\n", is_sorted(stack_a));
}

void	test_index_to_insert(t_stack *stack)
{
	print_stack(*stack);
	ft_printf("val:%d, res:%d\n", 0, index_to_insert(stack, 0));
	ft_printf("val:%d, res:%d\n", 100, index_to_insert(stack, 100));
	ft_printf("val:%d, res:%d\n", -100, index_to_insert(stack, -100));
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*solution;

	//TODO: check input: duplicates, non-numbers, numbres out of int range
	//TODO: optimize: use rr & rrr, use solve for 3
	//TODO: fix memory leaks
	//TODO: memory protection
	//TODO: norminette
	init_stacks(argc, argv, &stack_a, &stack_b);
	solution = calculate_solution(&stack_a, &stack_b);
	ft_printf("%s", solution);
	free(solution);
	free(stack_a.arr);
	free(stack_b.arr);
}
