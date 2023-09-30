/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:10:42 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/03/01 18:17:21 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

/*This function has the objective of transforming 
whole numbers into real numbers, it is basically
the ft_atoi of libft, but with a deal acquisition
for the transformation into decimal numbers.*/
double	ft_atoid(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal;
 
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0.0;
	decimal = 1.0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - 48);
	if (str[i] == '.')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - 48);
		decimal *= 10;
	}
	return (result / decimal * sign);
}

/*This function aims to print an error
message and guidance for the user.*/
static void	error_msg(void)
{
	ft_putstr_fd("\n\033[6;1;31m***** OPS, INVALID ARGUMENTS ! *****\033[0m\n\n", 1);
	ft_putstr_fd("Try to type: \"\033[1;35mMandelbrot\033[0m\"", 1);
	ft_putstr_fd("\033[0;7;32m (CAPITAL M)\033[0m\n", 1);
	ft_putstr_fd("     or   \n", 1);
	ft_putstr_fd("Try to type: \"\033[1;35mJulia -0.835 -0.2321\033[0m\"", 1);
	ft_putstr_fd("\033[0;7;32m(CAPITAL J)\033[0m\n\n", 1);
}

/*This function will receive the arguments
passed by the user on the command line 
and check if the arguments are correct, 
if so, will return 1, otherwise it will
call the function "error_msg()" and return 0.*/
int	verify_args(t_data *data, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 11) == 0)
	{
		data->fract = '1';
		return (1);
	}
	else if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0
		&& (isalpha_julia(argv[2]) || isalpha_julia(argv[3])))
		error_msg();
	else if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0
		&& ft_atoid(argv[2]) >= -2.0 && ft_atoid(argv[2]) <= 2.0
		&& ft_atoid(argv[3]) >= -2.0 && ft_atoid(argv[3]) <= 2.0)
	{
		data->fract = '2';
		data->kr = ft_atoid(argv[2]);
		data->ki = ft_atoid(argv[3]);
		return (1);
	}
	error_msg();
	return (0);
}

/*Here is the beginning of it all.*/
int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (verify_args(data, argc, argv))
		init_window(data);
	else
		free(data);
	return (0);
}
