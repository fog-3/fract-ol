/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:19:07 by fernando          #+#    #+#             */
/*   Updated: 2024/09/12 09:49:20 by fernando         ###   ########.fr       */
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

double  ft_atof(char *str)
{
    int     i;
    double  ret;
    double  n_deci;

    i = 0;
    while(str[i] && str[i] != '.')
        i++;
    if (!str[i])
    {
        ret = (double)ft_atoi(str);
        return (ret);
    }
    str[i] = '\0';
    ret = (double)ft_atoi(str);
    n_deci = (double)ft_atoi(&str[i + 1]);
    while (n_deci > 1)
        n_deci /= 10;
    while (str[++i] == '0')
        n_deci /= 10;
    if (str[0] == '-')
        return (ret - n_deci);
    return (ret + n_deci);

}

void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

t_cn    ft_complex(t_fractol *f, int  x, int  y)
{
    t_cn c;

    c.a = f->middle.a + 1.5 * f->range * (x / (double)WIDTH - 0.5);
    c.b = f->middle.b + 1.5 * f->range * (y / (double)HEIGHT - 0.5);
    return (c);
}
