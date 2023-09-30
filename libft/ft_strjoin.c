/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 05:06:55 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/02/02 00:03:44 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function has two parameters, it serves 
to join two strings into a new string using malloc
+ 1 to ensure that the NULL at the end.
I used the ft_strlen function as an auxiliary to 
get the size of s1 and s2, another important detail
is the casting, because we need to use it since
the parameters of the function are prototyped as "const".*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		size;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = (char *)malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		s2++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/*int main(void)
{
	char	str1[] = "William ";
	char	str2[] = "Daniel";
	char	*pstr;

	pstr = ft_strjoin(str1, str2);
	printf("%s \n", pstr);
}*/
