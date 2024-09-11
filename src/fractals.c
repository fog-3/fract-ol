/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:06:41 by fernando          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:14 by fernando         ###   ########.fr       */
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

/* int phoenix(t_cn c, t_cn args)
{
    t_cn    z;       // z_n: valor actual de la iteración
    t_cn    z_prev;  // z_{n-1}: valor anterior de la iteración
    t_cn z_temp;
    t_cn    z2;      // Cuadrados de las partes real e imaginaria de z
    int     i;
    double p;

    z.a = 1;
    z.b = 0;
    z_prev.a = 0;
    z_prev.b = 0;
    z2.a = 0;
    z2.b = 0;
    i = 0;
    (void)args;  // args no se utiliza en esta implementación
    p = -0.5;
    while (i < MAX_ITERATIONS && z2.a + z2.b < 4)
    {
        // Guardamos el valor actual de z en z_prev antes de actualizar z
        z_temp.a = z.a;
        z_temp.b = z.b;
        // Calculamos la nueva iteración: z_new = z^2 + c + p * z_prev
        z.b = 2 * z.a * z.b + c.b + p * z_prev.b;
        z.a = z2.a - z2.b + c.a + p * z_prev.a;

        // Actualizamos z_prev para la próxima iteración
        z_prev.a = z_temp.a;
        z_prev.b = z_temp.b;
        
        // Actualizamos los cuadrados de las partes real e imaginaria
        z2.a = z.a * z.a;
        z2.b = z.b * z.b;

        i++;
    }

    if (i == MAX_ITERATIONS)
        return (0);  // El punto pertenece al conjunto de Phoenix
    return (i);  // El punto no pertenece, devolvemos el número de iteraciones
} */

int phoenix(t_cn c, t_cn args)
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
