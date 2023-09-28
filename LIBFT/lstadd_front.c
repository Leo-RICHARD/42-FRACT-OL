/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:39:57 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/09 16:22:48 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		(*alst)->next = 0;
		(*alst)->previous = *alst;
	}
	else if (*alst && new)
	{
		new->next = *alst;
		new->previous = (*alst)->previous;
		(*alst)->previous = new;
		*alst = new;
	}
}
