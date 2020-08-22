/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:40:21 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:40:23 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_command(char *cmd)
{
	if (ft_strequ("sa", cmd) || ft_strequ("sb", cmd) || ft_strequ("ss", cmd) ||\
	ft_strequ("pa", cmd) || ft_strequ("pb", cmd) || ft_strequ("ra", cmd) ||\
	ft_strequ("rb", cmd) || ft_strequ("rr", cmd) || ft_strequ("rra", cmd) ||\
	ft_strequ("rrb", cmd) || ft_strequ("rrr", cmd))
		return (1);
	return (0);
}
