/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:03 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:06 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		run_r(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*ptr;

	if ((*stack) && (*stack)->next)
	{
		old_head = (*stack);
		new_head = (*stack)->next;
		ptr = (*stack);
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = old_head;
		old_head->next = NULL;
		(*stack) = new_head;
	}
}

static void		run_s(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*tmp;

	if ((*stack) && (*stack)->next)
	{
		old_head = (*stack);
		tmp = (*stack)->next;
		old_head->next = tmp->next;
		tmp->next = old_head;
		(*stack) = tmp;
	}
}

static void		run_p(t_stack **dest, t_stack **src)
{
	t_stack	*src_to_push;
	t_stack	*src_new_head;

	if (*src)
	{
		src_to_push = (*src);
		src_new_head = (*src)->next;
		src_to_push->next = (*dest);
		(*dest) = src_to_push;
		(*src) = src_new_head;
	}
}

static void		run_rr(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	tmp = (*stack);
	ptr = (*stack);
	if ((*stack) && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (ptr->next && ptr->next->value != tmp->value)
			ptr = ptr->next;
		ptr->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void			run_command(char *command, t_stack **a, t_stack **b)
{
	ft_strequ("sa", command) ? run_s(a) : 0;
	ft_strequ("sb", command) ? run_s(b) : 0;
	if (ft_strequ("ss", command))
	{
		run_s(a);
		run_s(b);
	}
	ft_strequ("pa", command) ? run_p(a, b) : 0;
	ft_strequ("pb", command) ? run_p(b, a) : 0;
	ft_strequ("ra", command) ? run_r(a) : 0;
	ft_strequ("rb", command) ? run_r(b) : 0;
	if (ft_strequ("rr", command))
	{
		run_r(a);
		run_r(b);
	}
	ft_strequ("rra", command) ? run_rr(a) : 0;
	ft_strequ("rrb", command) ? run_rr(b) : 0;
	if (ft_strequ("rrr", command))
	{
		run_rr(a);
		run_rr(b);
	}
}
