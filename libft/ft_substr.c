/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:30:53 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/27 00:06:11 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_np(void)
{
	char	*np;

	np = (char *) malloc(sizeof(char));
	np[0] = 0;
	return (np);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	j;
	size_t			max;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	if (start > max)
		return (ft_np());
	if (len >= max)
		len = max - start;
	substring = (char *) malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	j = 0;
	while (s[start] != '\0' && j < len)
	{
		substring[j] = (char) s[start];
		start++;
		j++;
	}
	substring[j] = '\0';
	return (substring);
}
