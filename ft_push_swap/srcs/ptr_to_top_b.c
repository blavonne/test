/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_top_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:30:31 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:32:27 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		try_rb(t_stack *ptr, t_stack *b, t_vector **rb)
{
	while (b && b->value != ptr->value)
	{
		if (!push_in_vector(rb, RB, sizeof(char)))
			return (0);
		b = b->next;
	}
	return (1);
}

static int		try_rrb(t_stack *ptr, t_stack *b, t_vector **rrb)
{
	t_stack		*copy;

	if (!(copy = copy_stack(b)))
		return (0);
	while (copy->value != ptr->value)
	{
		run_command("rrb", 0, &copy);
		if (!push_in_vector(rrb, RRB, sizeof(char)))
		{
			destroy_stack(&copy);
			return (0);
		}
	}
	destroy_stack(&copy);
	return (1);
}

t_vector		*ptr_to_top_b(t_stack *b, t_stack *ptr)
{
	t_vector	*rb;
	t_vector	*rrb;

	if (!(rb = create_vector()))
		return (NULL);
	if (!(rrb = create_vector()))
		return (NULL);
	if (!try_rb(ptr, b, &rb) || !try_rrb(ptr, b, &rrb))
	{
		destroy_vector(&rb);
		destroy_vector(&rrb);
		return (NULL);
	}
	if (rb->next < rrb->next)
	{
		destroy_vector(&rrb);
		return (rb);
	}
	else
	{
		destroy_vector(&rb);
		return (rrb);
	}
}
