/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:35:39 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 18:52:26 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;
	char	*ops;

	init_stacks(argc, argv, &stack_a, &stack_b);
	line = emptystr();
	ops = emptystr();
	while (line)
	{
		free(line);
		line = get_next_line(0);
		ft_strattach(&ops, line, 1);
	}
	exec_str(&stack_a, &stack_b, ops);
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
