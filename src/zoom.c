/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:04:43 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:40:03 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(t_param *prm, int x, int y, double factor)
{
	double	fl_x;
	double	fl_y;

	fl_x = fractal_coords(prm, x) + prm->xmin;
	fl_y = fractal_coords(prm, y) + prm->ymin;
	prm->zoom *= factor;
	if (factor > 1)
		prm->iter += 5;
	else
		prm->iter -= 5;
	prm->xmin = fl_x - fractal_coords(prm, prm->img_w) / 2;
	prm->ymin = fl_y - fractal_coords(prm, prm->img_h) / 2;
	return (0);
}
