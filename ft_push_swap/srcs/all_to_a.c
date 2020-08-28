/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_to_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:36:44 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:38:45 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_min_index(t_vector *count_steps_i)
{
	int		*arr;
	size_t	i;
	int		min;

	arr = count_steps_i->arr;
	min = -1;
	if (arr)
		min = 0;
	i = 0;
	while (arr && i < count_steps_i->next)
	{
		if (arr[i] < arr[min])
			min = i;
		i++;
	}
	return (min);
}

static int		merge_commands(t_stack **a, t_stack **b, t_info **m,\
		int count)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	if (!(*m)->arr_size || (*m)->cmd_arr == NULL ||\
	(*m)->cmd_arr[count] == NULL)
		return (0);
	arr = (*m)->cmd_arr[count]->arr;
	while (i < (*m)->cmd_arr[count]->next)
	{
		if (!(push_in_vector(&(*m)->cmd_c, arr[i], sizeof(char))))
			return (0);
		arr[i] == RA ? run_command("ra", a, b) : 0;
		arr[i] == RB ? run_command("rb", a, b) : 0;
		arr[i] == RR ? run_command("rr", a, b) : 0;
		arr[i] == SA ? run_command("sa", a, b) : 0;
		arr[i] == SB ? run_command("sb", a, b) : 0;
		arr[i] == PA ? run_command("pa", a, b) : 0;
		arr[i] == PB ? run_command("pb", a, b) : 0;
		arr[i] == RRA ? run_command("rra", a, b) : 0;
		arr[i] == RRB ? run_command("rrb", a, b) : 0;
		arr[i] == RRR ? run_command("rrr", a, b) : 0;
		i++;
	}
	return (1);
}

int				reset_cmd_arr(t_info **m)
{
	destroy_vector(&(*m)->count_steps_i);
	destroy_varr(m);
	if (!((*m)->count_steps_i = create_vector()))
		return (0);
	(*m)->arr_size = 1;
	(*m)->arr_next = 0;
	return (1);
}

void			all_to_a(t_stack **a, t_stack **b, t_info **m)
{
	t_stack	*ptr;
	int		shortest_way_index;

	if (*b)
	{
		(*m)->cmd_arr = create_varr();
		ptr = (*b);
		while (ptr)
		{
			if (!set_steps((*a), (*b), ptr, m))
				clean_and_exit(a, b, m, 'm');
			ptr = ptr->next;
		}
		shortest_way_index = find_min_index((*m)->count_steps_i);
		if (shortest_way_index < 0)
			clean_and_exit(a, b, m, 'm');
		if (!merge_commands(a, b, m, shortest_way_index))
			clean_and_exit(a, b, m, 'm');
		reset_cmd_arr(m);
		if ((*b) == NULL)
			return ;
		else
			all_to_a(a, b, m);
	}
}
