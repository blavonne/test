/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:40:40 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:40:42 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*copy_stack(t_stack *src)
{
	t_stack		*copy;
	t_stack		*copy_head;

	copy_head = NULL;
	if (src)
	{
		if (!(copy = create_stack()))
			return (NULL);
		copy_head = copy;
		while (src)
		{
			copy->value = src->value;
			if (src->next && !(copy->next = create_stack()))
			{
				destroy_stack(&copy_head);
				return (NULL);
			}
			copy = copy->next;
			src = src->next;
		}
	}
	return (copy_head);
}

int			push_in_stack(t_stack **stack, int value)
{
	t_stack	*ptr;

	if (!(*stack))
	{
		if (!((*stack) = create_stack()))
			return (0);
		(*stack)->value = value;
	}
	else if ((*stack))
	{
		ptr = (*stack);
		while (ptr->next)
			ptr = ptr->next;
		if (!(ptr->next = create_stack()))
			clean_and_exit(stack, 0, 0, 'm');
		ptr = ptr->next;
		ptr->value = value;
	}
	return (1);
}

t_stack		*create_stack(void)
{
	t_stack		*elem;

	if (!(elem = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	elem->value = 0;
	elem->next = NULL;
	return (elem);
}
