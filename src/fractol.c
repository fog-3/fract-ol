/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:02:55 by fernando          #+#    #+#             */
/*   Updated: 2024/09/12 11:08:41 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	t_cn	c;

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

void	ft_args(t_fractol *f, int argc, char **argv)
{
	if (argc == 2 && (argv[1][0] == '1' || argv[1][0] == 'M' ||
		argv[1][0] == 'm'))
	{
		f->middle = (t_cn){-1, 0};
		f->form = mandelbrot;
	}
	else if (argc == 2 && argv[1][0] == '3')
	{
		f->colors = 0x140301;
		f->middle = (t_cn){0, 0};
		f->form = burningship;
	}
	else if (argv[1][0] == '2' || argv[1][0] == 'j' || argv[1][0] == 'J')
	{
		f->middle = (t_cn){0, 0};
		f->form = julia;
		f->julia = (t_cn){-0.85, 0.2};
		f->range = 2.5;
		if (argc == 4)
			f->julia = (t_cn){ft_atof(argv[2]), ft_atof(argv[3])};
		else if (argc == 3 || argc > 4)
			help_msg2(f);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;
	t_img		img;

	if (argc < 2 || (argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '1'
		&& argv[1][0] != 'M' && argv[1][0] != 'm' && argv[1][0] != 'j' &&
		argv[1][0] != '3' && argv[1][0] != 'J'))
		help_msg(NULL);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	f.range = 2.75;
	f.colors = 0x012020;
	f.mx = 0;
	f.my = 0;
	f.img = img;
	ft_args(&f, argc, argv);
	render(&f);
	print_controls();
	mlx_hook(f.win, 2, 1L << 0, ft_key_hook, &f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
