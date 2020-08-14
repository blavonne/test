/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_math_b2n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:51:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:51:25 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integral.h"

t_integral			add_nbr(t_integral *elephant, long long fly)
{
	elephant->bigint[0] += fly;
	normalize_integral(elephant);
	return (*elephant);
}

t_integral			multiply_by_nbr(t_integral *elephant, long long fly)
{
	int		i;

	i = 0;
	elephant->length = set_len_integral(elephant);
	while (i < elephant->length)
	{
		elephant->bigint[i] *= fly;
		normalize_integral(elephant);
		i++;
	}
	return (*elephant);
}

t_integral			division_by_nbr(t_integral *res, int divider)
{
	int		i;

	i = res->length - 1;
	while (i >= 0)
	{
		if (i)
			res->bigint[i - 1] += (res->bigint[i] % divider) * BASE;
		res->bigint[i] /= divider;
		i--;
	}
	normalize_integral(res);
	return (*res);
}
