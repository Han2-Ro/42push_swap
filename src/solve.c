/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:51:37 by hrother           #+#    #+#             */
/*   Updated: 2023/11/24 23:13:11 by hrother          ###   ########.fr       */
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

void	exec_rotate(t_stack *stack_a, t_stack *stack_b, t_rotate rotate)
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

char	*final_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min_i;
	int		min_val;
	char	*result;

	result = emptystr();
	i = 0;
	min_val = 2147483647;
	while (i < stack_a->size)
	{
		if (stack_a->arr[i] < min_val)
		{
			min_i = i;
			min_val = stack_a->arr[i];
		}
		i++;
	}
	if (min_i + 1 < stack_a->size - min_i - 1)
		ft_strattach(&result, "rra\n", min_i + 1);
	else
		ft_strattach(&result, "ra\n", stack_a->size - min_i -1);
	return (exec_str(stack_a, stack_b, result));
}

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	char	*ops;

	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->arr[0] < stack_a->arr[1])
			ft_printf("sa\n");
		return ;
	}
	//TODO: what to do for size==4?
	if (stack_a->size >= 5)
		ft_printf(exec_str(stack_a, stack_b, "pb\npb\n"));
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
	ops = final_rotate(stack_a, stack_b);
	if (!ops)
		error("ERROR: malloc failed", stack_a, stack_b);
	ft_printf(ops);
	free(ops);
}
