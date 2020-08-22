/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:33 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:30:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			rotate(t_stack **a, t_info **m, char *cmd)
{
	t_stack			*copy;
	t_vector		*tmp;
	int				i;
	unsigned char	c;

	c = (ft_strequ(cmd, "ra")) ? RA : RRA;
	i = 0;
	tmp = NULL;
	if (!(copy = copy_stack((*a))))
		return (0);
	if (!(tmp = create_vector()))
	{
		destroy_stack(&copy);
		return (0);
	}
	while (!check_asc_order(copy, 0))
	{
		run_command(cmd, &copy, 0);
		push_in_vector(&tmp, c, sizeof(char));
		i++;
	}
	push_in_varr(m, tmp);
	destroy_stack(&copy);
	return (i);
}

int			sort_slice(t_stack **a, t_info **m)
{
	int		ra;
	int		rra;
	size_t	i;

	i = 0;
	if (!((*m)->cmd_arr = create_varr()))
		return (0);
	ra = rotate(a, m, "ra");
	rra = rotate(a, m, "rra");
	if (ra < rra)
	{
		cat_vectors(&(*m)->cmd_c, (*m)->cmd_arr[0]);
		while (i++ < (*m)->cmd_arr[0]->next)
			run_command("ra", a, 0);
	}
	else
	{
		while (i++ < (*m)->cmd_arr[1]->next)
			run_command("rra", a, 0);
		cat_vectors(&(*m)->cmd_c, (*m)->cmd_arr[1]);
	}
	if (!check_asc_order((*a), 0))
		return (0);
	return (1);
}

t_info		*get_commands(t_stack **a, t_stack **b)
{
	t_info		*info;

	if (!(info = create_main_struct()))
		clean_and_exit(a, b, 0, 'm');
	all_to_b(a, b, &info);
	all_to_a(a, b, &info);
	if (check_asc_order((*a), 0))
		return (info);
	if (!(ft_isslice(*a)))
		clean_and_exit(a, b, 0, 'm');
	if (!sort_slice(a, &info))
		clean_and_exit(a, b, &info, 'm');
	return (info);
}
