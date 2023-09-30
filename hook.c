/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:17:08 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/04/01 21:49:08 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	color(int n)
{
	if (n == MAXCONT)
		return (0x00000000);
	else
		return (COLOR_0 + COLOR_1 / COLOR_1 - COLOR_1 * n);
}

/*This function is used to destroy all open windows,
preventing memory leaks from occurring in the process.*/
int	total_destruction(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}

/*This function was created when the ESC key was pressed,
and it calls the specified function to close the windows.*/
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
		total_destruction(data);
	return (0);
}

int	zoom(int key, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (key == 4)
	{
		data->img.i_min -= data->img.i_min * data->img.scale;
		data->img.i_max -= data->img.i_max * data->img.scale;
		data->img.r_min -= data->img.r_min * data->img.scale;
		data->img.r_max -= data->img.r_max * data->img.scale;
	}
	if (key == 5)
	{
		data->img.i_min += data->img.i_min * data->img.scale;
		data->img.i_max += data->img.i_max * data->img.scale;
		data->img.r_min += data->img.r_min * data->img.scale;
		data->img.r_max += data->img.r_max * data->img.scale;
	}
	fractol(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

/*Hooks function is used to call Minilibx functions and 
thus pass the above two functions as parameters.*/
int	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 0, total_destruction, data);
	mlx_key_hook(data->win_ptr, handle_keypress, data);
	mlx_mouse_hook(data->win_ptr, zoom, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
