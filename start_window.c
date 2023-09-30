/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:14:13 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/03/01 18:08:35 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	isalpha_julia(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

/*This function will place a pixel on the coordinates (x, Y) of the image.*/
void	img_pix_put(t_img *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->addr + (y * mlx->line_len + x * (mlx->bpp / 8));
	*(unsigned int *)pixel = color;
}

/*This function initialize the variables one making a new image,
taking its address and printing a new image int he window.*/
int	image(t_data *data)
{
	data->img.r_min = -2.0;
	data->img.r_max = 2.0;
	data->img.i_min = -2.0;
	data->img.i_max = 2.0;
	data->img.scale = 0.2;
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!data->img.mlx_img)
		exit(MLX_ERROR);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	fractol(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit(MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "Fractol");
	if (!data->win_ptr)
		exit (MLX_ERROR);
	image(data);
	hooks(data);
	return (0);
}
