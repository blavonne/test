/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:51:34 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:51:36 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "fractional.h"

t_fractional		frac_five_power(t_fractional *snake, int power)
{
	int		i;
	int		corrector;

	snake->bigint[0] = 5;
	while (power > 1)
	{
		i = set_len_frac(snake);
		while (i >= 0)
		{
			corrector = 5 * snake->bigint[i];
			snake->bigint[i + 1] = snake->bigint[i + 1] + corrector % 10;
			snake->bigint[i] = corrector / 10;
			i--;
		}
		power--;
	}
	return (*snake);
}

t_fractional		addition_frac(t_fractional *one, t_fractional *two)
{
	t_fractional	left;
	t_fractional	right;
	int				i;

	i = 0;
	one->length = set_len_frac(one);
	two->length = set_len_frac(two);
	left = (one->length > two->length) ? *one : *two;
	right = (one->length <= two->length) ? *one : *two;
	while (i < right.length)
	{
		left.bigint[i] += right.bigint[i];
		i++;
		normalize_frac(&left);
	}
	return (left);
}
