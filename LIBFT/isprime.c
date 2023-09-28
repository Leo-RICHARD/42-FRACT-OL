/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:43:18 by lrichard          #+#    #+#             */
/*   Updated: 2021/09/19 14:57:05 by lrichard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	isprime(int nb)
{
	int	d;

	if (nb < 2)
		return (0);
	if (nb < 12 && (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11))
		return (1);
	d = 10;
	while (++d && nb % 2 && nb % 3 && nb % 5 && nb % 7 && nb % d)
		if (d > (nb / d))
			return (1);
	return (0);
}