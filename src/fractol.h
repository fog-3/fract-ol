/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:20:08 by fernando          #+#    #+#             */
/*   Updated: 2025/05/09 17:51:44 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "key.h"
# include <math.h>
# include <stdio.h>

/* Dimensions */
# define WIDTH 900
# define HEIGHT 900
# define MAX_ITERATIONS 100

typedef struct s_cn
{
	double	a;
	double	b;
}	t_cn;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		(*form)(t_cn, t_cn);
	double	range;
	t_cn	middle;
	t_cn	julia;
	int		mx;
	int		my;
	int		colors;
}	t_fractol;

int		end_fractol(t_fractol *f);
int		ft_key_hook(int keycode, t_fractol *f);
int		mouse_hook(int keycode, int x, int y, t_fractol *f);
void	clean_exit(int n, t_fractol *f);
void	print_controls(void);
void	help_msg(t_fractol *f);
t_cn	ft_complex(t_fractol *f, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	render(t_fractol *f);
double	ft_atof(char *str);
void	help_msg2(t_fractol *f);

//Fractals
int		mandelbrot(t_cn c, t_cn args);
int		burningship(t_cn c, t_cn args);
int		julia(t_cn c, t_cn args);

#endif