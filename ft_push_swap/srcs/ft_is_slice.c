/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_slice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:26:57 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:27:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_point(t_stack *a, t_stack *point, char order)
{
	t_stack	*ptr;
	int		i;

	ptr = point;
	if (order == 'a')
		i = (check_asc_order(point, 0)) ? 1 : 0;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if ((i == 1 && ptr && ptr->value < a->value) || (i == 2 && ptr &&
	ptr->value > a->value))
		return (1);
	return (0);
}

int		ft_isslice(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		while (ptr && ptr->next && ptr->value < ptr->next->value)
			ptr = ptr->next;
		if (!ptr || check_point(a, ptr->next, 'a'))
			return (1);
		else
			break ;
	}
	return (0);
}
