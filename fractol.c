/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 00:29:52 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/02/01 23:28:47 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	julia(double rc, double ic, t_data *data)
{
	int		n;
	double	tmp;

	n = 0;
	while (rc * rc + ic * ic < 4 && n < MAXCONT)
	{
		tmp = rc * rc - ic * ic + data->kr;
		ic = 2 * rc * ic + data->ki;
		rc = tmp;
		n++;
	}
	return (color(n));
}

unsigned int	mandelbrot(double rc, double ic)
{
	int		n;
	double	rz;
	double	iz;
	double	tmp;

	n = 0;
	rz = 0;
	iz = 0;
	while (rz * rz + iz * iz < 4 && n < MAXCONT)
	{
		tmp = rz * rz - iz * iz + rc;
		iz = 2 * rz * iz + ic;
		rz = tmp;
		n++;
	}
	return (color(n));
}

void	fractol(t_data *data)
{
	int		x;
	int		y;
	double	rc;
	double	ic;

	y = 0;
	while (y < W_HEIGHT)
	{
		ic = data->img.i_min + y
			* (data->img.i_max - data->img.i_min) / W_HEIGHT;
		x = 0;
		while (x < W_WIDTH)
		{
			rc = data->img.r_min + x
				* (data->img.r_max - data->img.r_min) / W_WIDTH;
			if (data->fract == '1')
				img_pix_put(&data->img, x, y, mandelbrot(rc, ic));
			else
				img_pix_put(&data->img, x, y, julia(rc, ic, data));
		x++;
		}
		y++;
	}
}
