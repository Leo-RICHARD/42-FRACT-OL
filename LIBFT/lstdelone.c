/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:39 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/11 18:51:24 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		if (lst->previous && (lst->previous)->next)
			(lst->previous)->next = lst->next;
		if (lst->next)
			(lst->next)->previous = lst->previous;
	}
	free(lst);
	lst = 0;
}
