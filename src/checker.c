/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:39 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 13:20:03 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;

	//TODO: print Error on invalid operation
	init_stacks(argc, argv, &stack_a, &stack_b);
	line = get_next_line(0);
	while (line)
	{
		if (!exec_str(&stack_a, &stack_b, line))
		{
			free(line);
			error("Error", &stack_a, &stack_b);
		}
		free(line);
		line = get_next_line(0);
	}
	//free(line);
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stack_a.arr);
	free(stack_b.arr);
}
