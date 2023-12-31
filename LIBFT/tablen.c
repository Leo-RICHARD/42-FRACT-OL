/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tablen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:05:55 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:39:25 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tablen(char **tab)
{
	char	**tabb;

	if (!tab)
		return (0);
	tabb = tab;
	while (*tabb)
		tabb++;
	return (tabb - tab);
}
