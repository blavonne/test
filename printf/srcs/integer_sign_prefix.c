/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_sign_prefix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:20:19 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:21 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	prefix_h(t_format *info, char option)
{
	if (ft_strchr("pxX", info->specifier) && info->flags & FLG_NBRSIGN)
	{
		if (option == 'p')
		{
			if (!info->z.llu && info->specifier != 'p')
				return (0);
			else
				info->specifier == 'X' ? ft_putstr("0X") : ft_putstr("0x");
		}
		else if (option == 's')
		{
			if (info->specifier == 'p')
				return (2);
			if (info->specifier != 'p' && !info->z.llu)
				return (0);
			if (info->specifier != 'p' && info->precision)
				return (2);
		}
	}
	return (0);
}

static int	prefix_o(t_format *info, char option)
{
	if (option == 'p')
	{
		if (!info->z.llu && info->precision)
			return (0);
		ft_putchar('0');
		if (!info->length[0] || info->length[0] == 'h')
			info->precision = info->precision ? info->precision - 1 : 0;
		if (info->length[0] == 'l' && !info->length[1])
			info->precision = info->precision ? info->precision - 1 : 0;
		if (info->length[0] == 'l' && info->length[1])
			info->precision = info->precision ? info->precision - 1 : 0;
	}
	else if (option == 's')
	{
		if (!info->z.llu && info->precision)
			return (0);
		else
			return (1);
	}
	return (0);
}

static int	sign_di(t_format *info, char option)
{
	if (option == 's')
	{
		if (info->flags & FLG_PLUS || info->flags & FLG_SPACE)
			return (1);
		if ((!info->length[0] || info->length[0] == 'h') && info->z.i < 0)
			return (1);
		if (info->length[0] == 'l' && !info->length[1] && info->z.l < 0)
			return (1);
		if (info->length[0] == 'l' && info->length[1] == 'l' && \
		info->z.ll < 0)
			return (1);
	}
	else if (option == 'p')
	{
		if ((!info->length[0] || info->length[0] == 'h') && info->z.i < 0)
			ft_putchar('-');
		else if (info->length[0] == 'l' && !info->length[1] && info->z.l < 0)
			ft_putchar('-');
		else if (info->length[0] == 'l' && info->length[1] == 'l' && \
		info->z.ll < 0)
			ft_putchar('-');
		else if (info->flags & FLG_PLUS || info->flags & FLG_SPACE)
			info->flags & FLG_PLUS ? ft_putchar('+') : ft_putchar(' ');
	}
	return (0);
}

int			sign(t_format *info, char option)
{
	if (ft_strchr("di", info->specifier))
		return (sign_di(info, option));
	if (info->specifier == 'o' && info->flags & FLG_NBRSIGN)
		return (prefix_o(info, option));
	if (ft_strchr("pxX", info->specifier) && info->flags & FLG_NBRSIGN)
		return (prefix_h(info, option));
	return (0);
}
