/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:50:23 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/01/26 20:42:34 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/*void	ft_putnbr_fd(int n, int fd)
{
	char	num;
	int		len;

	num = 0;
	len = 0;
	if (n >= 10)
	{
		num = n % 10 + '0';
		n /= 10;
		len += ft_putnbr_fd(n, fd);
		len += write(1, &num, 1);
	}
	else if (0 <= n && n <= 9)
	{
		n += '0';
		len += write(1, &n, 1);
	}
	else if (n < 0)
	{
		n *= (-1);
		len += write(1, "-", 1);
		len += ft_putnbr_fd(n, fd);
	}
}
*/