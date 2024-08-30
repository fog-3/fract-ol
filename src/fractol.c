/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:02:55 by fernando          #+#    #+#             */
/*   Updated: 2024/08/30 12:16:36 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractol *f)
{
	int x;
	int y;
	int iter;
	t_cn c;

	y = 0;
	(void)f;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = ft_complex(f, x, y);
			iter = f->form(c, f->julia);
			my_mlx_pixel_put(&f->img, x, y, iter * f->colors);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}

void clean_init(t_fractol *f, t_img *img)
{
	f = malloc(sizeof(t_fractol));
	if (!f)
	{
		ft_putendl_fd("Memory allocation error", 2);
		exit(-1);
	}
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "FRACT'OL");
	if (!f->win)
	{
		ft_putendl_fd("Error in the initialization of the window", 2);
		clean_exit(-1, f);
	}
	img->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	f->range = 2.5;
	f->colors = 0x0000FF;
	f->mx = 0;
	f->my = 0;
}

void ft_args(t_fractol *f, int argc, char *argv[])
{
	if (argc == 2 && (argv[1][0] == '1' || argv[1][0] == 'M' ||
		argv[1][0] == 'm'))
	{
		f->middle = (t_cn){-1, 0};
		f->form = mandelbrot;
	}
	/* else if (argc == 2 && argv[1][0] == '3')
	{
		f->middle = (t_cn){-1, 0};
		f->form = burningship;
	}
	else if (argv[1][0] == '2' || argv[1][0] == 'j')
	{
		f->middle = (t_cn){-1, 0};
		f->form = julia;
		f->julia = (t_cn){-0.85, 0.2};
		if (argc >= 4)
			f->julia = (t_cn){ft_atof(argv[2]), ft_atof(argv[3])};
		else if (argc == 3)
			help_msg(f);
	} */
}

void draw_rect(t_img *img, int b, int h, int x, int y, int color)
{
    int base = 0;
    int altura = 0;
    while (base < b)
    {
        my_mlx_pixel_put(img, x + base, y, color);
        my_mlx_pixel_put(img, x + base, y + h, color);
        base++;
    }
    while (altura < h)
    {
        my_mlx_pixel_put(img, x, y + altura, color);
        my_mlx_pixel_put(img, x + b, y + altura, color);
        altura++;
    }
}


int main(int argc, char *argv[])
{
	t_fractol f;
	t_img img;
	if (argc < 2 || (argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '1' &&
		argv[1][0] != 'M' && argv[1][0] != 'm' && argv[1][0] != 'j'))
		help_msg(NULL);
	//clean_init(&f, &img);
	ft_args(&f, argc, argv);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol");
	img.img = mlx_new_image(f.mlx, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	f.range = 2.75;
	f.colors = 0x3e5f8a;
	f.mx = 0;
	f.my = 0;
	f.img = img;
	render(&f);
	print_controls();
	mlx_key_hook(f.win, ft_key_hook, &f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	//mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
