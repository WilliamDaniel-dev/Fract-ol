/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 01:13:49 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/27 00:57:35 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *out, const char *ins, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*ins)
		return ((char *)out);
	i = 0;
	while (out[i] && i < len)
	{
		if (out[i] == ins[0])
		{
			j = 0;
			while (out[i + j] == ins[j] && i + j < len)
			{
				if (ins[j + 1] == '\0')
					return ((char *)&out[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
