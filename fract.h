/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:00:20 by wdaniel-          #+#    #+#             */
/*   Updated: 2023/03/30 19:41:07 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "libft/libft.h"

# define W_WIDTH 900
# define W_HEIGHT 800  
# define MLX_ERROR 1
# define ESC 65307
# define COLOR_0 0x0000FF
# define COLOR_1 0xFF00000
# define COLOR_2 0x7fffd4	
# define COLOR_3 0xdeb887

# define MAXCONT 100

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	r_min;
	double	r_max;
	double	i_min;
	double	i_max;
	double	scale;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		scale;
	char	fract;
	double	ki;
	double	kr;
	int		color;
}	t_data;

int				main(int argc, char **argv);
int				verify_args(t_data *data, int argc, char **argv);
double			ft_atoid(const char *str);
int				init_window(t_data *data);
int				image(t_data *data);
int				julia(double rc, double ic, t_data *data);
unsigned int	mandelbrot(double rc, double ic);
void			img_pix_put(t_img *mlx, int x, int y, int color);
int				total_destruction(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				hooks(t_data *data);
int				zoom(int key, int x, int y, t_data *data);
void			fractol(t_data *data);
int				color(int n);
int				isalpha_julia(char	*str);

#endif
