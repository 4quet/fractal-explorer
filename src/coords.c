/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:33:14 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:33:31 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	fractal_coords(t_param *prm, int a)
{
	return (a / prm->zoom);
}

int		screen_coords(t_param *prm, double a)
{
	return (a * prm->zoom);
}

void	ft_set_complex(t_param *prm, double cx[4], int x, int y)
{
	if (prm->type == 1)
	{
		cx[0] = fractal_coords(prm, x) + prm->xmin;
		cx[1] = fractal_coords(prm, y) + prm->ymin;
		cx[2] = prm->c_r;
		cx[3] = prm->c_i;
	}
	else
	{
		cx[0] = 0;
		cx[1] = 0;
		cx[2] = fractal_coords(prm, x) + prm->xmin;
		cx[3] = fractal_coords(prm, y) + prm->ymin;
	}
}
