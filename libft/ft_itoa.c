/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:35:39 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/27 22:58:41 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_numberlen(int nb)
{
	int	len;

	if (nb < 0)
	{
		len = 2;
		while (nb < -9)
		{
			nb = nb / 10;
			len++;
		}
	}
	if (nb >= 0)
	{
		len = 1;
		while (nb > 9)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	size;
	unsigned int	i;

	if (n == -2147483648)
		return (ft_strdup ("-2147483648"));
	size = ft_numberlen(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		n = n * -1;
		i++;
	}
	str[size] = '\0';
	while (size > i)
	{
		str[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}
