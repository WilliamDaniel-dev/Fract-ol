/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:21:14 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/02/02 00:05:29 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*This function called ft_bzero erases the data
in the "n" bytes of the memory starting at the
location pointed to by "s" by writing zeros 
(bytes con-taining '\0') to that area.
(Using the memset function as support). The  memset()
function  fills  the  first  n  bytes of the memory 
area pointed to by s with the constant byte c.*/
void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	ft_memset(tmp, '\0', n);
}

/*int	main(void)
{
	 const char a[] = "hola";
  ft_bzero(a,2);
	
	char	numb[];

	numb = "William";

	ft_bzero(a, numb);
	printf("Saida %c", numb);
	return (0);
}*/
