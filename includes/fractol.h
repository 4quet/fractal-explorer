/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourque <lfourque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 19:46:56 by lfourque          #+#    #+#             */
/*   Updated: 2015/03/03 23:14:26 by lfourque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "stdlib.h"
# include <mlx.h>
# include <math.h>

# define COLORS	3*256

typedef struct	s_param
{
	int			type;
	int			colorset;
	int			*color_map;
	int			mvt;
	int			img_w;
	int			img_h;
	int			iter;
	double		xmin;
	double		ymin;
	double		zoom;
	double		c_r;
	double		c_i;
}				t_param;

typedef struct	s_img
{
	void		*mlx;
	void		*win;
	void		*id;
	char		*data;
	int			bpp;
	int			line;
	int			endian;
	int			mousex;
	int			mousey;
	t_param		*prm;
}				t_img;

/*
**				fractal_type.c
*/
int				ft_valid_param(char *arg);
int				ft_valid_colorset(char *arg);
void			ft_print_usage(void);

/*
**				hooks.c
*/
int				expose_hook(t_img *img);
int				key_hook(int keycode, t_img *img);
int				mouse_hook(int button, int x, int y, t_img *img);
int				motion_hook(int x, int y, t_img *img);

/*
**				colorset.c
*/
int				ft_get_color(int red, int green, int blue);
int				*ft_set_grey(int *color_map);
int				*ft_set_frost(int *color_map);
int				*ft_set_fire(int *color_map);
int				*ft_set_toxic(int *color_map);

/*
**				init_param.c
*/
void			ft_init_param(t_param *prm);
int				*ft_cmap(int *color_map, int colorset);
void			ft_set_dim(t_param *prm);
double			ft_set_xmin(int type);
double			ft_set_ymin(int type);

/*
**				coords.c
*/
double			fractal_coords(t_param *prm, int a);
int				screen_coords(t_param *prm, double a);
void			ft_set_complex(t_param *prm, double cx[4], int x, int y);

/*
**				modulus.c
*/
double			modulus(double a, double b);
int				ft_mandelbrot_julia(t_param *prm, double cx[4]);
int				ft_burning_ship(t_param *prm, double cx[4]);

/*
**				draw.c
*/
void			ft_draw_image(t_img *img);
int				ft_pixel_is_valid(t_param *prm, int x, int y);
void			ft_pixel_to_image(t_img *img, int x, int y, int color);

/*
**				move_fractal.c
*/
int				move_fractal(t_param *prm, int x, int y);
void			ft_fractal_moving(t_param *prm, int keycode);

/*
**				zoom.c
*/
int				ft_zoom(t_param *prm, int x, int y, double factor);

void			put_error(void);

#endif
