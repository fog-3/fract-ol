/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:00:23 by fernando          #+#    #+#             */
/*   Updated: 2024/05/04 18:58:42 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    print_controls(void)
{
    ft_putendl_fd("\n+===============  Controls  =========================+", 1);
	ft_putendl_fd("WASD or arrow keys:\tmove view.", 1);
	ft_putendl_fd("Scroll wheel:\tzoom in and out.", 1);
	ft_putendl_fd("Presh key C:\tchange color schemes.", 1);
	ft_putendl_fd("Presh key N:\tshift Julia set [Julia only].", 1);
	ft_putendl_fd("ESC or close window:\tquit fract'ol.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}

void help_msg(t_fractol *f)
{
    ft_putendl_fd("You must add arguments:", 1);
    ft_putendl_fd("\n+====================================================+", 1);
    ft_putendl_fd("+=                FRACT'OL OPTIONS                  =+", 1);
    ft_putendl_fd("+====================================================+\n", 1);
    ft_putendl_fd("+=============== Avaliable Fractals =================+\n",1);
    ft_putendl_fd("\t1) Julia: puedes darle tus propios valores", 1);
    ft_putendl_fd("\t2) Mandelbrot", 1);
    ft_putendl_fd("\t3) Other(surprise)💚\n", 1);
    clean_exit(EXIT_FAILURE, f);
}
