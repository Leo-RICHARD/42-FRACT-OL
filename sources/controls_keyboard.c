/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <lrichard@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:11:23 by lrichard          #+#    #+#             */
/*   Updated: 2021/11/26 00:18:23 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	controls_k_press(int keycode, t_controls *inputs)
{
	if (keycode == 126)
		inputs->up = 1;
	else if (keycode == 125)
		inputs->down = 1;
	else if (keycode == 124)
		inputs->right = 1;
	else if (keycode == 123)
		inputs->left = 1;
	else if (keycode == 53)
		inputs->terminate = 1;
	else if (keycode == 69)
		inputs->iitmax = 1;
	else if (keycode == 78)
		inputs->ditmax = 1;
	else if (keycode == 34)
		inputs->display_iters = 1;
	else if (keycode == 111)
		inputs->screenshot = 1;
	return (1);
}

int	controls_k_release(int keycode, t_controls *inputs)
{
	if (keycode == 126)
		inputs->up = 0;
	else if (keycode == 125)
		inputs->down = 0;
	else if (keycode == 124)
		inputs->right = 0;
	else if (keycode == 123)
		inputs->left = 0;
	else if (keycode == 69)
		inputs->iitmax = 0;
	else if (keycode == 78)
		inputs->ditmax = 0;
	else if (keycode == 34)
		inputs->display_iters = 0;
	else if (keycode == 111)
		inputs->screenshot = 0;
	return (1);
}

void	apply_mvt(t_plan *plan, t_controls *inputs, double mvt)
{
	if (inputs->up)
	{
		plan->starty += mvt;
		plan->endy += mvt;
	}
	if (inputs->down)
	{
		plan->starty -= mvt;
		plan->endy -= mvt;
	}
	if (inputs->right)
	{
		plan->startx += mvt;
		plan->endx += mvt;
	}
	if (inputs->left)
	{
		plan->startx -= mvt;
		plan->endx -= mvt;
	}
}
