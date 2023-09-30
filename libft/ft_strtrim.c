/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:50:10 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/27 23:13:46 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*copy;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start == end)
	{
		copy = (char *) malloc(sizeof(char));
		copy[0] = 0;
		return (copy);
	}	
	while (end > start && ft_strrchr(set, s1[end]))
		end--;
	copy = ft_substr(s1, start, end - start + 1);
	return (copy);
}
