/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:27:48 by hannes            #+#    #+#             */
/*   Updated: 2023/11/24 17:38:52 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cost(t_rotate rot)
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

t_rotate	init_rotates(int nra, int nrra, int nrb, int nrrb)
{
	t_rotate	res;

	res.nra = nra;
	res.nrra = nrra;
	res.nrb = nrb;
	res.nrrb = nrrb;
	return (res);
}

t_rotate	select_best_rot(t_rotate rot)
{
	t_rotate	tmp;
	t_rotate	res;

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

t_rotate	generate_rot(t_stack *src, t_stack *dest, int ascending)
{
	t_rotate	res;
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
