/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:06 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:29:12 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		destroy_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if ((*stack))
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			ptr = tmp->next;
			free(tmp);
			tmp = ptr;
		}
		free(*stack);
	}
}

void		destroy_vector(t_vector **v)
{
	(*v) ? free((*v)->arr) : 0;
	(*v) ? (*v)->arr = NULL : 0;
	free(*v);
	(*v) = NULL;
}

void		destroy_varr(t_info **m)
{
	size_t	i;

	i = 0;
	if ((*m)->cmd_arr)
		while (i < (*m)->arr_size)
		{
			destroy_vector(&(*m)->cmd_arr[i]);
			(*m)->cmd_arr[i++] = NULL;
		}
	free((*m)->cmd_arr);
	(*m)->cmd_arr = NULL;
}

void		destroy_main(t_info **m)
{
	if ((*m))
	{
		destroy_vector(&(*m)->cmd_c);
		(*m)->cmd_c = NULL;
		destroy_vector(&(*m)->count_steps_i);
		(*m)->count_steps_i = NULL;
		destroy_varr(m);
	}
	free(*m);
	(*m) = NULL;
}

void		clean_and_exit(t_stack **a, t_stack **b, t_info **m,\
		char option)
{
	(a) && (*a) ? destroy_stack(a) : 0;
	(b) && (*b) ? destroy_stack(b) : 0;
	(m) && (*m) ? destroy_main(m) : 0;
	put_errmsg_and_exit(option);
}
