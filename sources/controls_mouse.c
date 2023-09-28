/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:34:07 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/22 15:47:19 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	controls_m_press(int button, int x, int y, t_hooker *h)
{
	if (button == 5)
		h->inputs->zoomin = 1;
	if (button == 4)
		h->inputs->zoomout = 1;
	h->inputs->mposx = x;
	h->inputs->mposy = y;
	return (1);
}

void	center_scope(t_plan *plan, int mposx, int mposy)
{
	plan->startx -= (XRES / 2 - mposx) * plan->step;
	plan->endx -= (XRES / 2 - mposx) * plan->step;
	plan->starty += (YRES / 2 - mposy) * plan->step;
	plan->endy += (YRES / 2 - mposy) * plan->step;
}

void	apply_zoom(t_plan *plan, t_controls *inputs, double zoom)
{
	if (inputs->zoomin)
	{
		center_scope(plan, inputs->mposx, inputs->mposy);
		plan->startx += zoom;
		plan->endx -= zoom;
		plan->starty -= (plan->starty - plan->endy) / 2;
		plan->endy = plan->starty - \
						((plan->endx - plan->startx) * YRES / XRES) / 2;
		plan->starty += ((plan->endx - plan->startx) * YRES / XRES) / 2;
		inputs->zoomin = 0;
	}
	if (inputs->zoomout)
	{
		center_scope(plan, inputs->mposx, inputs->mposy);
		plan->startx -= zoom;
		plan->endx += zoom;
		plan->starty -= (plan->starty - plan->endy) / 2;
		plan->endy = plan->starty - \
						((plan->endx - plan->startx) * YRES / XRES) / 2;
		plan->starty += ((plan->endx - plan->startx) * YRES / XRES) / 2;
		inputs->zoomout = 0;
	}
	plan->step = (plan->endx - plan->startx) / XRES;
	plan->itmax += (inputs->iitmax - inputs->ditmax);
	plan->itmax = plan->itmax * (plan->itmax > 0) + (plan->itmax < 1);
}
