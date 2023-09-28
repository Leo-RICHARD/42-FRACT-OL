/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:50:47 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/26 15:55:41 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <mlx.h>
# include <stdio.h>

# define XRES 1920
# define YRES 1080

typedef struct s_plan
{
	double		startx;
	double		endx;
	double		starty;
	double		endy;
	double		step;
	int			it;
	int			itmax;
	int			itmin;
	int			**path;
	int			ib;
	int			bx;
	int			by;
	double		zr;
	double		zi;
	double		ztmp;
	double		cr;
	double		ci;
}				t_plan;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bppx;
	int			linelen;
	int			endian;
	int			x;
	int			y;
	int			w;
	int			h;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*frame;
}				t_mlx;

typedef struct s_controls
{
	int			up;
	int			down;
	int			right;
	int			left;
	int			zoomin;
	int			zoomout;
	int			mposx;
	int			mposy;
	int			iitmax;
	int			ditmax;
	int			display_iters;
	int			screenshot;
	int			terminate;
}				t_controls;

typedef struct s_hooker
{
	t_mlx		*mlx;
	t_controls	*inputs;
	t_plan		*plan;
	char		*name;
	void		(*drawfract)();
}				t_hooker;

void			launch(t_plan *plan, void (*drawfract)());
void			set_scope(t_plan *plan, double startx, double endx);
void			draw_mandelbrot_set(t_img *frame, t_plan *plan);
void			draw_julia_set(t_img *frame, t_plan *plan);
void			draw_buddhabrot(t_img *frame, t_plan *plan);
int				controls_k_press(int keycode, t_controls *inputs);
int				controls_k_release(int keycode, t_controls *inputs);
int				controls_m_press(int butt, int x, int y, t_hooker *h);
void			apply_mvt(t_plan *plan, t_controls *inputs, double mvt);
void			apply_zoom(t_plan *plan, t_controls *inputs, double zoom);
void			take_screenshot(t_img *frame, char *name);

#endif
