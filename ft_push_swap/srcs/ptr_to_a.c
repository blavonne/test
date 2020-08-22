/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_to_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:35:07 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:35:31 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		try_to_push(int count, unsigned char cmd, t_vector **dest)
{
	int		i;

	i = 0;
	if (count < 0)
	{
		destroy_vector(dest);
		(*dest) = NULL;
		return (1);
	}
	while (i++ < count)
		if (!(push_in_vector(dest, cmd, sizeof(char))))
			return (0);
	return (1);
}

static int		try_ra(t_stack *a, t_stack *ptr, t_vector **ra)
{
	int				ra_count;
	long long int	min;
	int				i;

	i = 1;
	if (ptr && a)
	{
		min = ft_abs_ll(ptr->value - a->value);
		ra_count = (ptr->value < a->value) ? 0 : 1;
		a = (a->next) ? a->next : 0;
	}
	while (a && ptr)
	{
		if (ft_abs(ptr->value - a->value) < min)
		{
			ra_count = (ptr->value < a->value) ? i : i + 1;
			min = ft_abs(ptr->value - a->value);
		}
		i++;
		a = a->next;
	}
	return (try_to_push(ra_count, RA, ra));
}

static int		try_rra(t_stack *a, t_stack *ptr, t_vector **rra)
{
	int				rra_count;
	long long int	min;
	int				i;
	t_stack			*copy;

	if (!(copy = copy_stack(a)))
		return (0);
	i = 0;
	rra_count = 0;
	if (ptr)
		min = ft_abs_ll(ptr->value - copy->value) + 1;
	while (ptr)
	{
		if (ft_abs_ll(ptr->value - copy->value) < min)
		{
			rra_count = (ptr->value > copy->value) ? i - 1 : i;
			min = ft_abs_ll(ptr->value - copy->value);
		}
		run_command("rra", &copy, 0);
		if (copy->value == a->value)
			break ;
		i++;
	}
	destroy_stack(&copy);
	return (try_to_push(rra_count, RRA, rra));
}

static int		insert_way(t_vector **way, t_vector **less)
{
	if (*less)
	{
		if (!(cat_vectors(way, (*less))))
		{
			destroy_vector(less);
			return (0);
		}
		destroy_vector(less);
		(*less) = NULL;
		return (1);
	}
	return (0);
}

int				ptr_to_a(t_stack *a, t_stack *ptr, t_vector **way)
{
	t_vector	*ra;
	t_vector	*rra;
	t_vector	*less;

	if (!(ra = create_vector()))
		return (0);
	if (!(rra = create_vector()))
		return (0);
	if (!try_ra(a, ptr, &ra) || !try_rra(a, ptr, &rra))
	{
		destroy_vector(&ra);
		destroy_vector(&rra);
		return (0);
	}
	if (ra && rra)
		less = (ra->next < rra->next) ? copy_vector(ra) : copy_vector(rra);
	else
		less = (ra) ? copy_vector(ra) : copy_vector(rra);
	destroy_vector(&ra);
	destroy_vector(&rra);
	if (!less || !insert_way(way, &less))
		return (0);
	return (1);
}
