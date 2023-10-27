/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannes <hrother@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:48:36 by hrother           #+#    #+#             */
/*   Updated: 2023/10/27 19:49:15 by hannes           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(argc, argv, &stack_a, &stack_b);
	print_stack(stack_a);
	//print_stack(stack_b);
	convert_stack(&stack_a);
	print_stack(stack_a);
	ft_printf("%s\n", calculate_solution(&stack_a, &stack_b));
	print_stack(stack_a);
	//exec_str(&stack_a, &stack_b, "sa pb rrr ra pb sb pa");
	//ft_printf("%s", shortes_solve(stackdup(stack_a), stackdup(stack_b), "", 6));
	free(stack_a.arr);
	free(stack_b.arr);
}
