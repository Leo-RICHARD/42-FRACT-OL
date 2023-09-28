/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:42:53 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/09 16:23:41 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		alst = &new;
	else if (!*alst)
	{
		*alst = new;
		(*alst)->next = 0;
		(*alst)->previous = *alst;
	}
	else
	{
		tmp = lstlast(*alst);
		tmp->next = new;
		new->previous = tmp;
	}
}
