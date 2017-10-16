/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:03:21 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 20:04:46 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_fractal(t_param *prm, int x, int y)
{
	prm->xmin += fractal_coords(prm, x);
	prm->ymin += fractal_coords(prm, y);
	return (0);
}

void	ft_fractal_moving(t_param *prm, int keycode)
{
	if (keycode == 123)
		move_fractal(prm, 50, 0);
	else if (keycode == 125)
		move_fractal(prm, 0, -50);
	else if (keycode == 124)
		move_fractal(prm, -50, 0);
	else if (keycode == 126)
		move_fractal(prm, 0, 50);
}
