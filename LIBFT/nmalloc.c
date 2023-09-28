/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:22 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/12 17:39:44 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*nmalloc(void **var, int size)
{
	*var = malloc(sizeof(char) * size);
	if (!(*var))
		return (NULL);
	return (*var);
}

void	*nmallloc(void ***var, int size)
{
	*var = malloc(sizeof(char *) * size);
	if (!(*var))
		return (NULL);
	return (*var);
}

void	*nmallloc_2d(int ***var, int sizey, int sizex)
{
	int	i;
	int	i3;

	*var = (int **)malloc(sizeof(int *) * sizey);
	if (!(*var))
		return (NULL);
	i = -1;
	while (++i < sizey)
	{
		(*var)[i] = (int *)malloc(sizeof(int) * sizex);
		if (!(*var)[i])
		{
			i3 = -1;
			while (++i3 < i)
				free((*var)[i]);
			free(*var);
			return (NULL);
		}
		ft_bzero((*var)[i], sizex);
	}
	return (*var);
}
