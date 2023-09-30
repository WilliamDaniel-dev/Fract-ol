/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 03:46:17 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/17 04:55:04 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	count;

	count = 0;
	s = ft_strlen(src);
	d = ft_strlen(dst);
	if (size <= d)
		return (size + s);
	while ((count + d) < (size - 1) && src[count])
	{
		dst[d + count] = src[count];
		count++;
	}
		dst[d + count] = '\0';
	return (d + s);
}
