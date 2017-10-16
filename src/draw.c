/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 18:35:43 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 18:40:50 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_pixel_is_valid(t_param *prm, int x, int y)
{
	double	cx[4];

	ft_set_complex(prm, cx, x, y);
	if (prm->type < 3)
		return (ft_mandelbrot_julia(prm, cx));
	else
		return (ft_burning_ship(prm, cx));
}

void	ft_pixel_to_image(t_img *img, int x, int y, int color)
{
	int		i;
	char	*clr;

	i = (img->line * y) + (x * (img->bpp / 8));
	color = mlx_get_color_value(img->mlx, color);
	clr = (char *)&color;
	img->data[i] = clr[0];
	img->data[i + 1] = clr[1];
	img->data[i + 2] = clr[2];
	img->data[i + 3] = clr[3];
}

void	ft_draw_image(t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->prm->img_w)
	{
		y = 0;
		while (y < img->prm->img_h)
		{
			ft_pixel_to_image(img, x, y, ft_pixel_is_valid(img->prm, x, y));
			y++;
		}
		x++;
	}
}
