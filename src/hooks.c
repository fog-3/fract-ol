/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:24:39 by fernando          #+#    #+#             */
/*   Updated: 2024/08/30 12:22:35 by fernando         ###   ########.fr       */
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
        
    if (keycode == KEY_A || keycode == KEY_LEFT)

    if (keycode == KEY_S || keycode == KEY_DOWN)

    if (keycode == KEY_D || keycode == KEY_RIGHT)
    
    if (keycode == KEY_N)
    {
        f->julia.a += 0.01;
        f->julia.b -= 0.01;
    }
    render(f);
    return (0);
}
