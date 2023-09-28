/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:40:24 by lrichard          #+#    #+#             */
/*   Updated: 2021/10/11 18:47:59 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*list;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		tmp = list;
		list = list->next;
		lstdelone(tmp, del);
	}
	*lst = NULL;
}
