/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:49:09 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 23:15:54 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_error(void)
{
	ft_putendl_fd("An error occured in one of the minilibX functions", 2);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_img	img;
	t_param	prm;

	img.prm = &prm;
	if (argc != 3 || !(img.prm->type = ft_valid_param(argv[1])) ||
			(img.prm->colorset = ft_valid_colorset(argv[2])) == -1)
		ft_print_usage();
	else
	{
		if (!(img.mlx = mlx_init()))
			put_error();
		ft_init_param(img.prm);
		if (!(img.win = mlx_new_window(img.mlx, prm.img_w, prm.img_h,
			"fractol")))
			put_error();
		mlx_expose_hook(img.win, expose_hook, &img);
		mlx_key_hook(img.win, key_hook, &img);
		mlx_mouse_hook(img.win, mouse_hook, &img);
		mlx_hook(img.win, 6, (1L << 6), motion_hook, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
