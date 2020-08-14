/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_creation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:52:28 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:52:30 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integral.h"

static void			set_power(t_power *tmp, int exp, int base)
{
	int		overflow_power;

	overflow_power = 62;
	if (base == 10 || base == 5)
		overflow_power = (base == 10) ? 18 : 27;
	tmp->full = 0;
	tmp->rest = 0;
	tmp->rest = exp % overflow_power;
	exp -= tmp->rest;
	if (exp >= overflow_power)
		tmp->full = exp / overflow_power;
}

static t_integral	set_full(void)
{
	t_integral	full_62;

	initialize_integral(&full_62);
	full_62.bigint[0] = 427387904;
	full_62.bigint[1] = 611686018;
	full_62.bigint[2] = 4;
	full_62.length = set_len_integral(&full_62);
	return (full_62);
}

t_integral			create_integral(int base, int exp)
{
	t_power		power;
	t_integral	one;
	t_integral	two;

	set_power(&power, exp, base);
	initialize_integral(&one);
	initialize_integral(&two);
	if (power.rest)
		add_nbr(&one, ft_pow(base, power.rest));
	else if (power.full)
	{
		one = set_full();
		power.full--;
	}
	while (power.full)
	{
		two = set_full();
		one = multiply(&one, &two);
		power.full--;
	}
	if (!exp)
		one.bigint[0] = 1;
	return (one);
}
