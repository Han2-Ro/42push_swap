/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:32:22 by hrother           #+#    #+#             */
/*   Updated: 2023/09/10 17:57:33 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(size * sizeof(char));
	if (!result)
		return (result);
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}
