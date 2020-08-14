/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:10:49 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:03 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			int_basic(t_format *info, va_list *arg)
{
	int		recasted;

	if (info->length[0] == 'h')
	{
		recasted = va_arg(*arg, int);
		if (info->length[1] == 0)
		{
			if (ft_strchr("di", info->specifier))
				info->z.i = (short)recasted;
			if (ft_strchr("ouxX", info->specifier))
				info->z.i = (unsigned short)recasted;
		}
		if (info->length[1] == 'h')
		{
			if (ft_strchr("di", info->specifier))
				info->z.i = (char)recasted;
			if (ft_strchr("ouxX", info->specifier))
				info->z.i = (unsigned char)recasted;
		}
	}
}

static void			int_long(t_format *info, va_list *arg)
{
	unsigned long int	recasted;

	if (info->length[0] == 'l' && info->length[1] == 0)
	{
		recasted = va_arg(*arg, unsigned long int);
		if (ft_strchr("di", info->specifier))
			info->z.l = (long)recasted;
		if (ft_strchr("ouxX", info->specifier))
			info->z.lu = recasted;
	}
}

static void			int_llong(t_format *info, va_list *arg)
{
	unsigned long long	recasted;

	if (info->length[0] == 'l' && info->length[1] == 'l')
	{
		recasted = va_arg(*arg, unsigned long long int);
		if (ft_strchr("di", info->specifier))
			info->z.ll = (long long)recasted;
		if (ft_strchr("ouxX", info->specifier))
			info->z.llu = recasted;
	}
}

static void			initialize_arg(t_format *info, va_list *arg)
{
	if (info->length[0] == 'h')
		int_basic(info, arg);
	else if (info->length[0] == 'l' && info->length[1] == 0)
		int_long(info, arg);
	else if (info->length[0] == 'l' && info->length[1] == 'l')
		int_llong(info, arg);
	else
		info->z.i = va_arg(*arg, int);
}

int					integer(t_format *info, va_list *arg)
{
	int		count;

	initialize_arg(info, arg);
	count = 0;
	if (info->flags & FLG_MINUS)
		count = flg_minus_case(info);
	else if (info->flags & FLG_ZERO)
		count = flg_zero_case(info);
	else
		count = flg_others_case(info);
	return (count);
}
