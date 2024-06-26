/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:06:41 by fernando          #+#    #+#             */
/*   Updated: 2024/04/26 19:19:43 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_cn c, t_cn args)
{
    t_cn    z;
    t_cn    z2;
    int     i;
    
    z.a = 0;
    z.b = 0;
    z2.a = 0;
    z2.b = 0;
    i = 0;
    (void)args;
    while (i < MAX_ITERATIONS && z2.a + z2.b < 4)
    {
        z.b = 2 * z.a * z.b + c.b;
        z.b = z2.a - z2.b + c.a;
        z2.a = z.a * z.a;
        z2.b = z.b * z.b;
        i++;
    }
    if (i == MAX_ITERATIONS)
        return (0);
    return (i);
}
