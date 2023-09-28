/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:11:06 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/26 15:51:01 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	leave(t_hooker *h)
{
	int	i;

	mlx_destroy_image(h->mlx->mlx, h->mlx->frame->img);
	mlx_destroy_window(h->mlx->mlx, h->mlx->window);
	i = -1;
	while (++i < YRES)
		free(h->plan->path[i]);
	free(h->plan->path);
	free(h->name);
	exit(1);
	return (0);
}

void	set_scope(t_plan *plan, double startx, double endx)
{
	plan->startx = startx;
	plan->endx = endx;
	plan->starty = ((plan->endx - plan->startx) * YRES / XRES) / 2;
	plan->endy = -((plan->endx - plan->startx) * YRES / XRES) / 2;
	plan->step = (plan->endx - plan->startx) / XRES;
}

void	init_things(t_hooker *h)
{
	h->inputs->up = 0;
	h->inputs->down = 0;
	h->inputs->right = 0;
	h->inputs->left = 0;
	h->inputs->zoomin = 0;
	h->inputs->zoomout = 0;
	h->inputs->iitmax = 0;
	h->inputs->ditmax = 0;
	h->inputs->display_iters = 0;
	h->inputs->terminate = 0;
	h->plan->path = 0;
	h->name = 0;
	if (!nmallloc_2d((int ***)&h->plan->path, YRES, XRES) || \
		!nmalloc((void **)&h->name, 19))
	{
		prints("Memory allocation failed\n");
		leave(h);
	}
	ft_strncpy(h->name, "screenshot////.bmp", 19);
	h->plan->ib = 1;
	h->plan->itmin = h->plan->itmax * 0.001;
}

int	refresh(t_hooker *h)
{
	if (h->inputs->terminate)
		leave(h);
	if (h->inputs->screenshot)
		take_screenshot(h->mlx->frame, h->name);
	apply_mvt(h->plan, h->inputs, h->plan->step * 42);
	apply_zoom(h->plan, h->inputs, h->plan->step * 127);
	h->drawfract(h->mlx->frame, h->plan);
	mlx_put_image_to_window(h->mlx->mlx, h->mlx->window, \
			h->mlx->frame->img, 0, 0);
	if (h->inputs->display_iters)
	{
		prints("iterations threshold : ");
		printn(h->plan->itmax);
		write(1, "\n", 1);
	}
	return (1);
}

void	launch(t_plan *plan, void (*drawfract)())
{
	t_mlx		mlx;
	t_img		frame;
	t_controls	inputs;
	t_hooker	h;

	mlx.mlx = mlx_init();
	frame.img = mlx_new_image(mlx.mlx, XRES, YRES);
	frame.addr = (int *)mlx_get_data_addr(frame.img, &frame.bppx, \
												&frame.linelen, &frame.endian);
	mlx.window = mlx_new_window(mlx.mlx, XRES, YRES, "fract-ol");
	mlx.frame = &frame;
	h.mlx = &mlx;
	h.inputs = &inputs;
	h.plan = plan;
	h.drawfract = drawfract;
	init_things(&h);
	mlx_hook(mlx.window, 2, 1L << 0, controls_k_press, &inputs);
	mlx_hook(mlx.window, 3, 1L << 1, controls_k_release, &inputs);
	mlx_hook(mlx.window, 4, 1L << 2, controls_m_press, &h);
	mlx_hook(mlx.window, 17, 1L << 17, leave, &h);
	mlx_loop_hook(mlx.mlx, refresh, &h);
	drawfract(mlx.frame, plan);
	mlx_put_image_to_window(mlx.mlx, mlx.window, frame.img, 0, 0);
	mlx_loop(mlx.mlx);
}
