/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:39 by hrother           #+#    #+#             */
/*   Updated: 2023/10/08 22:34:06 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*ops;

	init_stacks(argc, argv, &stack_a, &stack_b);
	//read operations
	exec_str(&stack_a, &stack_b, ops);
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
