/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotset_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:27:48 by hannes            #+#    #+#             */
/*   Updated: 2023/11/25 14:37:22 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cost(t_rotset rot)
{
	int	res;

	if (rot.nra > rot.nrb)
		res = rot.nra;
	else
		res = rot.nrb;
	if (rot.nrra > rot.nrrb)
		res += rot.nrra;
	else
		res += rot.nrrb;
	return (res);
}

t_rotset	init_rotates(int nra, int nrra, int nrb, int nrrb)
{
	t_rotset	res;

	res.nra = nra;
	res.nrra = nrra;
	res.nrb = nrb;
	res.nrrb = nrrb;
	return (res);
}

t_rotset	select_best_rot(t_rotset rot)
{
	t_rotset	tmp;
	t_rotset	res;

	res = init_rotates(rot.nra, 0, rot.nrb, 0);
	tmp = init_rotates(rot.nra, 0, 0, rot.nrrb);
	if (cost(tmp) < cost(res))
		res = tmp;
	tmp = init_rotates(0, rot.nrra, rot.nrb, 0);
	if (cost(tmp) < cost(res))
		res = tmp;
	tmp = init_rotates(0, rot.nrra, 0, rot.nrrb);
	if (cost(tmp) < cost(res))
		res = tmp;
	return (res);
}

t_rotset	generate_rot(t_stack *src, t_stack *dest, int ascending)
{
	t_rotset	res;
	int			i_src;
	int			i_dest;

	i_src = find_next_nbr(src, dest, ascending);
	i_dest = index_to_insert(dest, src->arr[i_src], ascending);
	res.nra = src->size - i_src - 1;
	res.nrra = i_src + 1;
	res.nrb = dest->size - i_dest - 1;
	res.nrrb = i_dest + 1;
	return (select_best_rot(res));
}

void	exec_rotset(t_stack *stack_a, t_stack *stack_b, t_rotset rotate)
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
