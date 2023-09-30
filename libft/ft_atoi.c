/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 04:56:06 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/02/07 11:09:25 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <unistd.h>
#include <stdio.h>

/*ft_atoi the mimics a atoi the original converts the initial portion 
of the string pointed to by nptr to int*/
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

/*int		main()
{
	char	*str;
	int		will;

	str = "-422822";

	will = ft_atoi(str);
	printf("Segue tudo iss: %d\n", will);
		printf("ft_atoi X atoi\n");
	printf("    %d X", ft_atoi("   +342"));
	printf(" %d\n", atoi("         +342"));
	printf("   %d X", ft_atoi("    -342"));
	printf(" %d\n", atoi("         -342"));
	printf("      %d X", ft_atoi(" --342"));
	printf(" %d\n", atoi("         --342"));
	printf("      %d X", ft_atoi(" ++342"));
	printf(" %d\n", atoi("         ++342"));
	printf("      %d X", ft_atoi(" +-342"));
	printf(" %d\n", atoi("         +-342"));
	return (0);
}*/
