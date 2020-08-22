/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:27:21 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:31:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_info **m)
{
	t_vector	*way;

	if (!(way = ptr_to_top_b(b, ptr)))
		return (0);
	if (!ptr_to_a(a, ptr, &way))
		return (0);
	if (!push_in_vector(&way, PA, sizeof(char)))
		return (0);
	optimize_way(way);
	if (!push_in_varr(m, way))
	{
		destroy_vector(&way);
		return (0);
	}
	if (!(push_in_vector(&(*m)->count_steps_i, way->next, sizeof(int))))
	{
		destroy_vector(&way);
		return (0);
	}
	return (1);
}
