/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannes <hrother@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:27:48 by hannes            #+#    #+#             */
/*   Updated: 2023/11/24 00:56:40 by hannes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int cost(t_rotates rot)
{
	int res;

	if (rot.nra > rot.nrb)
		res = rot.nra;
	else
		res = rot.nrb;
	if (rot.nrra > rot.nrrb)
		res = rot.nrra;
	else
		res = rot.nrrb;
	return (res);
}

t_rotates init_rotates(int nra, int nrra, int nrb, int nrrb)
{
	t_rotates res;

	res.nra = nra;
	res.nrra = nrra;
	res.nrb = nrb;
	res.nrrb = nrrb;
	return (res);
}

int generate_rot(t_stack *src, t_stack *dest, int ascending)
{
	t_rotates res;
	int i_src;
	int i_dest;

	//TODO: int indixis
	res.nra = src->size - i_src - 1;
	res.nrra = i_src + 1;
	res.nrb = dest->size - i_dest - 1;
	res.nrrb = i_dest + 1;
}
