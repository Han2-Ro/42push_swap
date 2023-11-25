/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:51:37 by hrother           #+#    #+#             */
/*   Updated: 2023/11/25 13:41:00 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*swap_stacks(char *str)
{
	int	i;

	if (!str)
		return (str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			str[i] = 'b';
		else if (str[i] == 'b')
			str[i] = 'a';
		i++;
	}
	return (str);
}

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

static void	exec_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate rotate)
{
	while (rotate.nra && rotate.nrb)
	{
		ft_printf("%s", exec_str(stack_a, stack_b, "rr\n"));
		rotate.nra--;
		rotate.nrb--;
	}
	while (rotate.nra-- > 0)
		ft_printf("%s", exec_str(stack_a, stack_b, "ra\n"));
	while (rotate.nrb-- > 0)
		ft_printf("%s", exec_str(stack_a, stack_b, "rb\n"));
	while (rotate.nrra && rotate.nrrb)
	{
		ft_printf("%s", exec_str(stack_a, stack_b, "rrr\n"));
		rotate.nrra--;
		rotate.nrrb--;
	}
	while (rotate.nrra-- > 0)
		ft_printf("%s", exec_str(stack_a, stack_b, "rra\n"));
	while (rotate.nrrb-- > 0)
		ft_printf("%s", exec_str(stack_a, stack_b, "rrb\n"));
}

void	push_next_nbr(t_stack *src, t_stack *dest, int btoa)
{
	t_rotate	rotate;

	rotate = generate_rot(src, dest, btoa);
	if (btoa)
	{
		ft_swap(&rotate.nra, &rotate.nrb);
		ft_swap(&rotate.nrra, &rotate.nrrb);
		exec_rotate(dest, src, rotate);
	}
	else
		exec_rotate(src, dest, rotate);
	if (btoa)
		ft_printf(exec_str(dest, src, "pa\n"));
	else
		ft_printf(exec_str(src, dest, "pb\n"));
	update_offset(src, !btoa);
	update_offset(dest, btoa);
}

void	final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	update_offset(stack_a, 1);
	exec_rotate (stack_a, stack_b, init_rotates(0, stack_a->offset, 0, 0));
}

void	solve_bigger3(t_stack *stack_a, t_stack *stack_b)
{
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
