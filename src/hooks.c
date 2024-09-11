/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:24:39 by fernando          #+#    #+#             */
/*   Updated: 2024/09/11 09:16:18 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int end_fractol(t_fractol *f)
{
    clean_exit(0, f);
    return (0);
}

int   ft_key_hook(int keycode, t_fractol *f)
{
    if (keycode == KEY_C)
        f->colors *= 1.001;
    if (keycode == KEY_ESC)
        end_fractol(f);
    if (keycode == KEY_W || keycode == KEY_UP)
        f->middle.b -= f->range / 4;
    if (keycode == KEY_A || keycode == KEY_LEFT)
        f->middle.a -= f->range / 4;
    if (keycode == KEY_S || keycode == KEY_DOWN)
        f->middle.b += f->range / 4;
    if (keycode == KEY_D || keycode == KEY_RIGHT)
        f->middle.a += f->range / 4;
    if (keycode == KEY_N)
    {
        f->julia.a += 0.05;
        f->julia.b -= 0.05;
    }
    render(f);
    return (0);
}

int mouse_hook(int keycode, int x, int y, t_fractol *f)
{
    t_fractol	*vars;
	t_cn	p2;

	(void)x;
    (void)y;
	vars = (t_fractol *)f;
	p2 = ft_complex(vars, x, y);
	if (keycode == 4)
	{
		vars->middle = (t_cn){(vars->middle.a + p2.a) / 2,
			(vars->middle.b + p2.b) / 2};
		vars->range *= 0.5;
	}
	else if (keycode == 5)
	{
		vars->middle = (t_cn){2 * vars->middle.a - p2.a,
			2 * vars->middle.b - p2.b};
		vars->range *= 2;
	}
	render(vars);
    return (0);
}
