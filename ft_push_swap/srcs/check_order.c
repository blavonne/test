/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:26:00 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:26:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_asc_order(t_stack *a, t_stack *b)
{
	if (b || a == NULL)
		return (0);
	else if (a)
	{
		while (a->next)
		{
			if (a->value >= a->next->value)
				return (0);
			a = a->next;
		}
	}
	return (1);
}
