/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:28:45 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/26 15:55:39 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_path(int **pathtab)
{
	int	i;
	int	i3;

	i = -1;
	while (++i < YRES)
	{
		i3 = -1;
		while (++i3 < XRES)
			pathtab[i][i3] = 0;
	}
}

void	light_path(t_img *frame, t_plan *plan)
{
	plan->ib++;
	plan->itmax *= 11;
	plan->itmin = plan->itmax * 0.001;
	if (plan->ib < 4)
		draw_buddhabrot(frame, plan);
	else
	{
		frame->y = -1;
		while (++frame->y < YRES)
		{
			frame->x = -1;
			while (++frame->x < XRES)
				frame->addr[frame->y * XRES + \
							frame->x] = plan->path[frame->y][frame->x];
		}
		plan->ib = 1;
		init_path(plan->path);
		plan->itmax /= 1331;
		plan->itmin = plan->itmax * 0.001;
	}
}

static inline void	save_path(t_plan *plan, int iter)
{
	plan->zr = 0;
	plan->zi = 0;
	while (iter--)
	{
		plan->ztmp = plan->zr;
		plan->zr = (plan->zr * plan->zr) - (plan->zi * plan->zi) + plan->cr;
		plan->zi = (plan->ztmp + plan->ztmp) * plan->zi + plan->ci;
		plan->bx = (int)((plan->zr - plan->startx) / plan->step);
		plan->by = (int)((plan->starty - plan->zi) / plan->step);
		if (plan->bx > -1 && plan->bx < XRES && \
			plan->by > -1 && plan->by < YRES)
		{
			if (plan->ib == 1)
				plan->path[plan->by][plan->bx] += 0x9;
			else if (plan->ib == 2)
				plan->path[plan->by][plan->bx] += 0x600;
			else
				plan->path[plan->by][plan->bx] += 0x30000;
		}
	}
}

void	draw_buddhabrot(t_img *frame, t_plan *plan)
{
	frame->y = -1;
	while (++frame->y < YRES)
	{
		plan->ci = plan->starty - frame->y * plan->step;
		frame->x = -1;
		while (++frame->x < XRES)
		{
			plan->cr = plan->startx + frame->x * plan->step;
			plan->zr = 0;
			plan->zi = 0;
			plan->it = -1;
			while (++plan->it <= plan->itmax && \
					plan->zr * plan->zr + plan->zi * plan->zi <= 4)
			{
				plan->ztmp = plan->zr;
				plan->zr = plan->zr * plan->zr - plan->zi * plan->zi + \
							plan->cr;
				plan->zi = plan->ztmp * (plan->zi + plan->zi) + plan->ci;
			}
			if (plan->it <= plan->itmax && plan->it > plan->itmin)
				save_path(plan, plan->it);
		}
	}
	light_path(frame, plan);
}
