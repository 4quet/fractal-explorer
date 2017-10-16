/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:52:46 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 19:13:22 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_usage(void)
{
	ft_putendl_fd("usage: ./fractol [fractal type] [colorset]\n", 2);
	ft_putendl_fd("fractal types:", 2);
	ft_putendl_fd("- \"julia\"", 2);
	ft_putendl_fd("- \"mandelbrot\"", 2);
	ft_putendl_fd("- \"burning ship\"\n", 2);
	ft_putendl_fd("color sets:", 2);
	ft_putendl_fd("- \"blue\"", 2);
	ft_putendl_fd("- \"red\"", 2);
	ft_putendl_fd("- \"green\"", 2);
	ft_putendl_fd("- \"black\"\n", 2);
	ft_putendl_fd("Fractal type and color set must be lowercase", 2);
}

int		ft_valid_param(char *arg)
{
	if (!ft_strcmp(arg, "julia"))
		return (1);
	if (!ft_strcmp(arg, "mandelbrot"))
		return (2);
	if (!ft_strcmp(arg, "burning ship"))
		return (3);
	return (0);
}

int		ft_valid_colorset(char *arg)
{
	if (!ft_strcmp(arg, "blue"))
		return (1);
	if (!ft_strcmp(arg, "red"))
		return (2);
	if (!ft_strcmp(arg, "green"))
		return (3);
	if (!ft_strcmp(arg, "black"))
		return (4);
	return (-1);
}
