/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:06:42 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/14 02:21:15 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error(void)
{
	prints("It doesn't work like that.\nUsage :\n\n");
	prints(\
	"[--mandelbrot]			    - to explore the Mandelbrot set\n");
	prints(\
	"[--julia] [c real] [c imaginary]    - to explore the Julia set\n");
	prints(\
	"[--buddhabrot] [iterations]	    - for the buddhabro\n\n");
	prints("(One at a time, thank you)");
	return (0);
}

int	isdouble(char *s)
{
	int	dotfound;

	dotfound = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!((*s > 47 && *s < 58) || *s == '.') || (*s == '.' && dotfound))
			return (0);
		if (*s == '.')
			dotfound = 1;
		s++;
	}
	return (1);
}

double	atodd(char *s)
{
	int		wasneg;
	double	n;
	double	nn;

	wasneg = 0;
	if (*s == '-')
		wasneg = 1;
	nn = (double)ft_atoi(s);
	while (*s && *(s++) != '.')
		;
	n = (double)ft_atoi(s);
	while (n >= 1 || (*s && *s++ == '0'))
		n /= 10;
	nn += n;
	if (nn > 0 && wasneg)
		nn *= -1;
	return (nn);
}

int	check_args(int ac, char **av)
{
	if ((ac == 2 && ft_strcmp(av[1], "--mandelbrot")) || \
		(ac == 3 && (ft_strcmp(av[1], "--buddhabrot") || !aredigits(av[2]))) \
		|| (ac == 4 && (ft_strcmp(av[1], "--julia") || \
					!isdouble(av[2]) || !isdouble(av[3]))) || \
		(ac < 2 || ac > 4))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_plan	plan;

	if (!check_args(ac, av))
		return (error());
	if (ac == 2)
	{
		plan.itmax = 43;
		set_scope(&plan, -3, 1.5);
		launch(&plan, &draw_mandelbrot_set);
	}
	else if (ac == 3)
	{
		plan.itmax = ft_atoi(av[2]);
		set_scope(&plan, -2.6, 1.6);
		launch(&plan, &draw_buddhabrot);
	}
	else
	{
		plan.itmax = 136;
		set_scope(&plan, -2, 2);
		plan.cr = atodd(av[2]);
		plan.ci = atodd(av[3]);
		launch(&plan, &draw_julia_set);
	}
	return (0);
}
