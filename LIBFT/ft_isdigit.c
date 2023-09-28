/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:24:53 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/29 05:54:47 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	aredigits(char *s)
{
	while (*s)
	{
		if (!(*s > 47 && *s < 58))
			return (0);
		s++;
	}
	return (1);
}
