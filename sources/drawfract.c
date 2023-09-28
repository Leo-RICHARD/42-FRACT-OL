/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawfract.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 17:21:39 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/14 02:26:24 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot_set(t_img *frame, t_plan *plan)
{
	frame->y = -1;
	while (++frame->y < YRES)
	{
		plan->ci = plan->starty - frame->y * plan->step;
		frame->x = -1;
		while (++frame->x < XRES)
		{
			plan->zr = 0;
			plan->zi = 0;
			plan->cr = plan->startx + frame->x * plan->step;
			plan->it = -1;
			while (++plan->it <= plan->itmax && \
					plan->zr * plan->zr + plan->zi * plan->zi <= 4)
			{
				plan->ztmp = plan->zr;
				plan->zr = plan->zr * plan->zr - plan->zi * plan->zi + \
							plan->cr;
				plan->zi = plan->ztmp * (plan->zi + plan->zi) + plan->ci;
			}
			frame->addr[frame->y * XRES + frame->x] = \
			(0xFFFFFF / plan->itmax) * plan->it * (plan->it <= plan->itmax);
		}
	}
}

void	draw_julia_set(t_img *frame, t_plan *plan)
{
	frame->y = -1;
	while (++frame->y < YRES)
	{
		frame->x = -1;
		while (++frame->x < XRES)
		{
			plan->zi = plan->starty - frame->y * plan->step;
			plan->zr = plan->startx + frame->x * plan->step;
			plan->it = -1;
			while (++plan->it <= plan->itmax && \
					plan->zr * plan->zr + plan->zi * plan->zi <= 4)
			{
				plan->ztmp = plan->zr;
				plan->zr = plan->zr * plan->zr - plan->zi * plan->zi + \
							plan->cr;
				plan->zi = plan->ztmp * (plan->zi + plan->zi) + plan->ci;
			}
			frame->addr[frame->y * XRES + frame->x] = \
			(0xFFFFFF / plan->itmax) * plan->it * (plan->it <= plan->itmax);
		}
	}
}
