/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:30:06 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:39:13 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	modulus(double a, double b)
{
	return (a * a + b * b);
}

int		ft_burning_ship(t_param *prm, double cx[4])
{
	int		i;
	double	xsq;
	double	ysq;

	i = 0;
	while (i < prm->iter)
	{
		xsq = cx[0] * cx[0];
		ysq = cx[1] * cx[1];
		if (xsq + ysq > 10)
			return (prm->color_map[i * (COLORS - 1) / prm->iter]);
		cx[1] = fabs(2 * cx[0] * cx[1]) + cx[3];
		cx[0] = xsq - ysq + cx[2];
		i++;
	}
	return (0);
}

int		ft_mandelbrot_julia(t_param *prm, double cx[4])
{
	double	tmp;
	int		i;

	i = 0;
	while (modulus(cx[0], cx[1]) < 4 && i < prm->iter)
	{
		tmp = cx[0];
		cx[0] = cx[0] * cx[0] - cx[1] * cx[1] + cx[2];
		cx[1] = 2 * tmp * cx[1] + cx[3];
		i++;
	}
	if (i == prm->iter)
		return (0xFFFFFF);
	return (prm->color_map[i * (COLORS - 1) / prm->iter]);
}
