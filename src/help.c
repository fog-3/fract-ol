/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:00:23 by fernando          #+#    #+#             */
/*   Updated: 2024/09/12 10:52:55 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_controls(void)
{
	ft_putendl_fd("\n+=================  Controls  ======================+", 1);
	ft_putendl_fd("WASD or arrow keys:\tmove view.", 1);
	ft_putendl_fd("Scroll wheel:\t\tzoom in and out.", 1);
	ft_putendl_fd("Presh key C:\t\tchange color schemes.", 1);
	ft_putendl_fd("Presh key N:\t\tshift Julia set [Julia only].", 1);
	ft_putendl_fd("ESC or close window:\tquit fract'ol.", 1);
	ft_putendl_fd("+===================================================+\n", 1);
}

void	help_msg(t_fractol *f)
{
	ft_putendl_fd("You must add arguments:", 1);
	ft_putendl_fd("\n+===================================================+", 1);
	ft_putendl_fd("+=                FRACT'OL OPTIONS                 =+", 1);
	ft_putendl_fd("+===================================================+\n", 1);
	ft_putendl_fd("+=============== Avaliable Fractals ================+", 1);
	ft_putendl_fd("    1) Mandelbrot", 1);
	ft_putendl_fd("    2) Julia: you can give the values that you want", 1);
	ft_putendl_fd("    3) Other(surprise)💚", 1);
	ft_putendl_fd("+===================================================+\n", 1);
	clean_exit(EXIT_FAILURE, f);
}

void	help_msg2(t_fractol *f)
{
	ft_putendl_fd("Number of arguments in Julia are wrong:", 1);
	ft_putendl_fd("\nExample of use with more than one argument:", 1);
	ft_putendl_fd("\n   +=================================+", 1);
	ft_putendl_fd("   +=      ./fractol 2 -0.4 0.6     =+", 1);
	ft_putendl_fd("   +=================================+\n", 1);
	clean_exit(EXIT_FAILURE, f);
}
