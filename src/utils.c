/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:19:07 by fernando          #+#    #+#             */
/*   Updated: 2024/08/28 22:34:18 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    clean_exit(int n, t_fractol *f)
{
    if (!f)
        exit(n);
    if (f->img.img)
    {
        mlx_destroy_image(f->mlx, f->img.img);
    }
	if (f->win && f->mlx)
    {
		mlx_destroy_window(f->mlx, f->win);
    }  
    if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
    }
	exit(n);
}

/* double  ft_atof(char *str)
{
    
} */

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
    // img->addr[x * 4 + y * WIDTH * 4] = color;
    // img->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
    // img->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
    // img->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

t_cn    ft_complex(t_fractol *f, int  x, int  y)
{
    t_cn c;

    c.a = f->middle.a + 1.5 * f->range * (x / (double)WIDTH - 0.5);
    c.b = f->middle.b + 1.5 * f->range * (y / (double)HEIGHT - 0.5);
    return (c);
}
