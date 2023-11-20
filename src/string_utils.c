/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:28:38 by hrother           #+#    #+#             */
/*   Updated: 2023/11/06 17:39:15 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*emptystr(void)
{
	char	*str;

	str = malloc(sizeof(char));
	str[0] = '\0';
	return (str);
}

int	count_ops(char *str)
{
	int	res;

	if (!str)
		return (2147483647);
	res = 0;
	while (*str)
	{
		if (*str == '\n')
			res++;
		str++;
	}
	return (res);
}

char	*ft_strattach(char **str, char *to_attach, int repeats)
{
	char	*result;

	if (repeats < 1)
		return (*str);
	result = ft_strjoin(*str, to_attach);
	free(*str);
	*str = result;
	ft_strattach(str, to_attach, repeats - 1);
	return (*str);
}