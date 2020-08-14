/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:52:16 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:52:18 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integral.h"

t_integral			initialize_integral(t_integral *elephant)
{
	int		i;

	i = 0;
	while (i < SIZE)
	{
		elephant->bigint[i] = 0;
		i++;
	}
	return (*elephant);
}

void				normalize_integral(t_integral *elephant)
{
	int			i;
	int			corrector;
	int			j;

	i = 0;
	elephant->length = set_len_integral(elephant);
	while (i < elephant->length)
	{
		if (elephant->bigint[i] >= BASE && i < SIZE)
		{
			corrector = (int)(elephant->bigint[i] / BASE);
			elephant->bigint[i] = elephant->bigint[i] % BASE;
			j = i + 1;
			while (corrector && j < SIZE)
			{
				elephant->bigint[j++] += corrector % BASE;
				corrector /= BASE;
			}
		}
		i++;
		elephant->length = set_len_integral(elephant);
	}
}

int					set_len_integral(t_integral *elephant)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < SIZE)
	{
		if (elephant->bigint[i])
			len = i + 1;
		i++;
	}
	return (len);
}

t_integral			get_integral(int exp, char *mantissa)
{
	t_integral	result;
	t_integral	temp;
	int			i;

	i = 0;
	initialize_integral(&temp);
	initialize_integral(&result);
	if (exp >= 0)
	{
		temp = create_integral(2, exp - i);
		exp = get_mant_len(mantissa);
		while (i < exp)
		{
			if (mantissa[i] == '1')
				result = addition(&result, &temp);
			temp = division_by_nbr(&temp, 2);
			i++;
		}
		if (mantissa[i] == '1')
			result.bigint[0]++;
	}
	result.length = set_len_integral(&result);
	return (result);
}
