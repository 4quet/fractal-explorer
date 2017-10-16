/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:13:23 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:25:35 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_color(int red, int green, int blue)
{
	return (red * 65536 + green * 256 + blue);
}

int	*ft_set_grey(int *color_map)
{
	int	i;

	i = 0;
	color_map = (int *)malloc(sizeof(int) * COLORS);
	while (i < 256)
	{
		color_map[i] = ft_get_color(i, i, i);
		color_map[i + 256] = ft_get_color(255 - i, 255 - i, 255 - i);
		color_map[i + 2 * 256] = ft_get_color(i, i, i);
		i++;
	}
	return (color_map);
}

int	*ft_set_frost(int *color_map)
{
	int	i;

	i = 0;
	color_map = (int *)malloc(sizeof(int) * COLORS);
	while (i < 256)
	{
		color_map[i] = ft_get_color(0, 0, i);
		color_map[i + 256] = ft_get_color(0, i, 255);
		color_map[i + 2 * 256] = ft_get_color(i, 255, 255);
		i++;
	}
	return (color_map);
}

int	*ft_set_fire(int *color_map)
{
	int	i;

	i = 0;
	color_map = (int *)malloc(sizeof(int) * COLORS);
	while (i < 256)
	{
		color_map[i] = ft_get_color(i, 0, 0);
		color_map[i + 256] = ft_get_color(255, i, 0);
		color_map[i + 2 * 256] = ft_get_color(255, 255, i);
		i++;
	}
	return (color_map);
}

int	*ft_set_toxic(int *color_map)
{
	int	i;

	i = 0;
	color_map = (int *)malloc(sizeof(int) * COLORS);
	while (i < 256)
	{
		color_map[i] = ft_get_color(0, i, 0);
		color_map[i + 256] = ft_get_color(i, 255, 0);
		color_map[i + 2 * 256] = ft_get_color(255, 255, i);
		i++;
	}
	return (color_map);
}
