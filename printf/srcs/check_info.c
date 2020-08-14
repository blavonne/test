/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:07:26 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:31 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		check_flags_and_specifier(t_format *info)
{
	if (info->specifier == '%')
		return ;
	if (info->flags & FLG_NBRSIGN && !(ft_strchr("oxXfF", info->specifier)))
		info->flags &= ~FLG_NBRSIGN;
	if (info->flags & FLG_MINUS && ft_strchr("n", info->specifier))
		info->flags &= ~FLG_MINUS;
	if (info->flags & FLG_ZERO && !ft_strchr("diouxXfFs", info->specifier))
		info->flags &= ~FLG_ZERO;
	if (info->flags & FLG_PLUS && !(ft_strchr("dioxXfF%", info->specifier)))
		info->flags &= ~FLG_PLUS;
	if ((info->flags & FLG_SPACE || info->flags & FLG_PLUS) &&\
		ft_strchr("ouxX", info->specifier))
		info->flags = (info->flags & (~FLG_SPACE)) & (~FLG_PLUS);
}

static void		check_length_and_specifier(t_format *info)
{
	if (info->length[0] && info->length[0] == 'l' && !info->length[1] &&\
		!ft_strchr("diouxXncs", info->specifier))
		info->length[0] = 0;
	if (info->length[0] && info->length[0] == 'h' && !info->length[1] &&\
		!ft_strchr("diouxXn", info->specifier))
		info->length[0] = 0;
	if (info->length[0] && info->length[0] == 'l' && info->length[1] == 'l'\
	&& !ft_strchr("diouxXn", info->specifier))
		ft_bzero(info->length, 2);
	if (info->length[0] && info->length[0] == 'h' && info->length[1] == 'h'\
	&& !ft_strchr("diouxXn", info->specifier))
		ft_bzero(info->length, 2);
	if (info->length[0] && ft_strchr("jzt", info->length[0]) &&\
	!(ft_strchr("diouxX", info->specifier)))
		info->length[0] = 0;
	if (info->length[0] && !ft_strchr("fF", info->specifier) &&\
	info->length[0] == 'L')
		info->length[0] = 0;
}

int				check_info(t_format *info, va_list *arg)
{
	if (info->width == READ_ARG && (info->width = va_arg(*arg, int)) &&\
	info->width < 0 && info->specifier != 'n')
	{
		set_flag('-', info);
		info->width = -info->width;
	}
	if (info->precision == READ_ARG && (info->precision = va_arg(*arg, int)))
		info->precision = info->precision < 0 ? -1 : info->precision;
	if (info->precision != -1 && info->flags & FLG_ZERO &&\
	!(ft_strchr("fF", info->specifier)))
		info->flags = info->flags & (unsigned char)(~FLG_ZERO);
	check_flags_and_specifier(info);
	check_length_and_specifier(info);
	if (!ft_strchr("diouxXfcsp%", info->specifier))
		put_errmsg_and_exit('u');
	return (0);
}

char			*check_inf_nan(t_format *info)
{
	char		*res;

	res = NULL;
	if (info->r.exponent == INF && get_mant_len(info->r.mantissa) == 1)
	{
		if (!(res = ft_strnew(3)))
			put_errmsg_and_exit('m');
		res = ft_strcpy(res, "inf");
	}
	if (info->r.exponent == INF && get_mant_len(info->r.mantissa) > 1)
	{
		if (!(res = ft_strnew(3)))
			put_errmsg_and_exit('m');
		res = ft_strcpy(res, "nan");
	}
	return (res);
}
