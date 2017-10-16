/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 16:22:16 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:29:30 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_set_ymin(int type)
{
	if (type == 1)
		return (-1.5);
	else if (type == 2)
		return (-1.2);
	else
		return (-1.8);
}

double	ft_set_xmin(int type)
{
	if (type == 1)
		return (-2);
	else if (type == 2)
		return (-2.1);
	else
		return (-2.2);
}

void	ft_set_dim(t_param *prm)
{
	if (prm->type == 1)
	{
		prm->img_h = 300;
		prm->img_w = 400;
	}
	else
	{
		prm->img_h = 500;
		prm->img_w = prm->type == 2 ? 600 : 700;
	}
}

int		*ft_cmap(int *color_map, int colorset)
{
	if (colorset == 1)
		color_map = ft_set_frost(color_map);
	else if (colorset == 2)
		color_map = ft_set_fire(color_map);
	else if (colorset == 3)
		color_map = ft_set_toxic(color_map);
	else if (colorset == 4)
		color_map = ft_set_grey(color_map);
	return (color_map);
}

void	ft_init_param(t_param *prm)
{
	if (prm)
	{
		ft_set_dim(prm);
		prm->iter = prm->type == 3 ? 150 : 50;
		prm->mvt = 0;
		prm->xmin = ft_set_xmin(prm->type);
		prm->ymin = ft_set_ymin(prm->type);
		prm->c_r = -0.6;
		prm->c_i = 0.6;
		prm->zoom = prm->type == 1 ? 100 : 200;
		prm->color_map = ft_cmap(prm->color_map, prm->colorset);
	}
}
