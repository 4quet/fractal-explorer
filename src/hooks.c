/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:12:23 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 23:10:45 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	expose_hook(t_img *img)
{
	if (!(img->id = mlx_new_image(img->mlx, img->prm->img_w, img->prm->img_h)))
		put_error();
	if (!(img->data = mlx_get_data_addr(img->id, &img->bpp, &img->line,
			&img->endian)))
		put_error();
	ft_draw_image(img);
	mlx_put_image_to_window(img->mlx, img->win, img->id, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_img *img)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && img->prm->iter < 2000)
		img->prm->iter += 15;
	if (keycode == 78 && img->prm->iter > 15)
		img->prm->iter -= 15;
	if (keycode > 17 && keycode < 22 && keycode - 17 != img->prm->colorset)
	{
		img->prm->colorset = keycode - 17;
		img->prm->color_map = ft_cmap(img->prm->color_map, img->prm->colorset);
	}
	if (keycode < 127 && keycode > 122)
		ft_fractal_moving(img->prm, keycode);
	if (keycode == 46)
		img->prm->mvt = img->prm->mvt == 1 ? 0 : 1;
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->id);
	expose_hook(img);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_img *img)
{
	if (button == 5)
		ft_zoom(img->prm, x, y, 1.2);
	if (button == 4 && img->prm->zoom > 25)
		ft_zoom(img->prm, x, y, 0.8);
	if (button == 3)
		ft_init_param(img->prm);
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->id);
	expose_hook(img);
	return (0);
}

int	motion_hook(int x, int y, t_img *img)
{
	static int	oldx = 0;
	static int	oldy = 0;

	if (img->prm->type == 1 && img->prm->mvt)
	{
		if (x > oldx)
			img->prm->c_r += 0.8 / img->prm->zoom;
		else
			img->prm->c_r -= 0.8 / img->prm->zoom;
		if (y > oldy)
			img->prm->c_i += 0.8 / img->prm->zoom;
		else
			img->prm->c_i -= 0.8 / img->prm->zoom;
		oldx = x;
		oldy = y;
		mlx_clear_window(img->mlx, img->win);
		mlx_destroy_image(img->mlx, img->id);
		expose_hook(img);
	}
	return (0);
}
