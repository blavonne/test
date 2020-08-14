/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_math_b2b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:51:06 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:51:14 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integral.h"

t_integral		multiply(t_integral *one, t_integral *two)
{
	t_integral	res;
	int			i;
	int			j;

	i = 0;
	res = initialize_integral(&res);
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE - i)
		{
			res.bigint[i + j] += one->bigint[i] * two->bigint[j];
			normalize_integral(&res);
			j++;
		}
		i++;
	}
	normalize_integral(&res);
	res.length = set_len_integral(&res);
	return (res);
}

t_integral		addition(t_integral *one, t_integral *two)
{
	t_integral	left;
	t_integral	right;
	int			i;

	i = 0;
	one->length = set_len_integral(one);
	two->length = set_len_integral(two);
	initialize_integral(&left);
	left = (one->length > two->length) ? *one : *two;
	right = (one->length <= two->length) ? *one : *two;
	while (i < right.length)
	{
		left.bigint[i] += right.bigint[i];
		i++;
	}
	normalize_integral(&left);
	return (left);
}

t_integral		substraction(t_integral *one, t_integral *two)
{
	t_integral	left;
	t_integral	right;
	int			i;

	i = 0;
	initialize_integral(&left);
	left = (one->length > two->length) ? *one : *two;
	right = (one->length < two->length) ? *one : *two;
	while (i < right.length)
	{
		left.bigint[i] -= right.bigint[i];
		i++;
	}
	normalize_integral(&left);
	return (left);
}
