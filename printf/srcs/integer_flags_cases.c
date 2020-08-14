/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_flags_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:16:49 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:08 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		flg_minus_case(t_format *info)
{
	int		count;

	count = (!info->z.llu && !info->precision) ? 0 : nbr_len(info);
	sign(info, 'p');
	while (info->precision != -1 && count < info->precision)
	{
		ft_putchar('0');
		count++;
	}
	count += sign(info, 's');
	print_arg(info);
	while (info->width != -1 && count < info->width)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}

int		flg_zero_case(t_format *info)
{
	int		count;

	count = nbr_len(info) + sign(info, 's');
	sign(info, 'p');
	while (count < info->width)
	{
		ft_putchar('0');
		count++;
	}
	print_arg(info);
	return (count);
}

int		flg_others_case(t_format *info)
{
	int		i;
	int		count;

	i = 0;
	if (info->specifier == 'o' && info->flags & FLG_NBRSIGN && info->precision\
	> nbr_len(info))
		info->flags &= ~FLG_NBRSIGN;
	count = (!info->z.llu && !info->precision) ? 0 : nbr_len(info);
	while (info->width != -1 && info->precision >= count && info->width >\
	info->precision + sign(info, 's') + i++)
		ft_putchar(' ');
	while (info->width != -1 && info->precision < count && info->width >\
	count + sign(info, 's') + i++)
		ft_putchar(' ');
	sign(info, 'p');
	while (info->precision != -1 && count < info->precision)
	{
		ft_putchar('0');
		count++;
	}
	count = i ? count + (i - 1) + sign(info, 's') : count + i +\
	sign(info, 's');
	print_arg(info);
	return (count);
}
