/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:06:41 by fernando          #+#    #+#             */
/*   Updated: 2024/09/12 11:08:26 by fernando         ###   ########.fr       */
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
        z.a = z2.a - z2.b + c.a;
        z2.a = z.a * z.a;
        z2.b = z.b * z.b;
        i++;
    }
    if (i == MAX_ITERATIONS)
        return (0);
    return (i);
}

int	julia(t_cn c, t_cn args)
{
	t_cn	z2;
	int		i;
	t_cn	z;

	z2.a = c.a * c.a;
	z2.b = c.b * c.b;
	z = args;
	i = 0;
	while (i < MAX_ITERATIONS && z2.a + z2.b < 4)
	{
		c.b = 2 * c.a * c.b + z.b;
		c.a = z2.a - z2.b + z.a;
		z2.a = c.a * c.a;
		z2.b = c.b * c.b;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return (0);
	return (i);
}

int burningship(t_cn c, t_cn args)
{
	t_cn	z;
	t_cn	z2;
	int		i;
	double	prod;

	(void)args;
	z.a = 0;
	z.b = 0;
	z2.a = 0;
	z2.b = 0;
	i = 0;
	while (i < MAX_ITERATIONS && z2.a + z2.b < 4)
	{
		prod = z.a * z.b;
		if (prod < 0)
			prod = -prod;
		z.b = 2 * prod + c.b;
		z.a = z2.a - z2.b + c.a;
		z2.a = z.a * z.a;
		z2.b = z.b * z.b;
		i++;
	}
	if (i == MAX_ITERATIONS)
		return (0);
	return (i);
}
