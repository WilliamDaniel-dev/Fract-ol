/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:07:13 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/01/26 20:30:17 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;
	char	a;

	a = (char) c;
	ptr = (char *) s;
	i = 0;
	while (a != ptr[i] && i < n)
		i++;
	if (i == n)
		return (ptr = 0);
	return (&ptr[i]);
}
