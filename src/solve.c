/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:51:37 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 15:24:32 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*solve_3stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->arr[0] > stack_a->arr[1] && stack_a->arr[0] > stack_a->arr[2])
	{
		if (stack_a->arr[1] > stack_a->arr[2])
			return ("");
		else
			return (exec_str(stack_a, stack_b, "sa\n"));
	}
	else if (stack_a->arr[1] > stack_a->arr[0]
		&& stack_a->arr[1] > stack_a->arr[2])
	{
		if (stack_a->arr[2] > stack_a->arr[0])
			return ("");
		else
			return (exec_str(stack_a, stack_b, "sa\n"));
	}
	else if (stack_a->arr[2] > stack_a->arr[0]
		&& stack_a->arr[2] > stack_a->arr[1])
	{
		if (stack_a->arr[0] > stack_a->arr[1])
			return ("");
		else
			return (exec_str(stack_a, stack_b, "sa\n"));
	}
	return (0);
}

void	push_next_nbr(t_stack *src, t_stack *dest, int btoa)
{
	t_rotset	rotate;

	rotate = generate_rot(src, dest, btoa);
	if (btoa)
	{
		ft_swap(&rotate.nra, &rotate.nrb);
		ft_swap(&rotate.nrra, &rotate.nrrb);
		exec_rotset(dest, src, rotate);
	}
	else
		exec_rotset(src, dest, rotate);
	if (btoa)
		ft_printf(exec_str(dest, src, "pa\n"));
	else
		ft_printf(exec_str(src, dest, "pb\n"));
	update_offset(src, !btoa);
	update_offset(dest, btoa);
}

void	final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	nra;
	int	nrra;

	nra = stack_a->size - stack_a->offset;
	nrra = stack_a->offset;
	update_offset(stack_a, 1);
	if (nra < nrra)
		exec_rotset (stack_a, stack_b, init_rotates(nra, 0, 0, 0));
	else
		exec_rotset (stack_a, stack_b, init_rotates(0, nrra, 0, 0));
}

void	solve_bigger3(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	ft_printf(exec_str(stack_a, stack_b, "pb\n"));
	update_offset(stack_a, 1);
	update_offset(stack_b, 0);
	while (stack_a->size > 3)
	{
		push_next_nbr(stack_a, stack_b, 0);
	}
	ft_printf(solve_3stack(stack_a, stack_b));
	update_offset(stack_a, 1);
	update_offset(stack_b, 0);
	while (stack_b->size > 0)
	{
		push_next_nbr(stack_b, stack_a, 1);
	}
	final_rotate(stack_a, stack_b);
}

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->arr[0] < stack_a->arr[1])
			ft_printf("sa\n");
		return ;
	}
	else if (stack_a->size == 3)
		ft_printf(solve_3stack(stack_a, stack_b));
	else if (stack_a->size > 3)
		solve_bigger3(stack_a, stack_b);
}
