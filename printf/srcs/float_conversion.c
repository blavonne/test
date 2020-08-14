/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 05:59:00 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:42 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		floats(t_format *info, va_list *arg)
{
	int			count;
	long double	ld;
	char		*res;

	count = 0;
	ld = 0;
	res = NULL;
	if (info->length[0] && info->length[0] == 'L')
		ld = va_arg(*arg, long double);
	else if (!info->length[0])
		ld = (long double)va_arg(*arg, double);
	info->r = initialize_float(ld);
	info->precision = info->precision < 0 ? 6 : info->precision;
	res = get_arg_f(info);
	res = process_flags_f(info, res);
	if (res)
	{
		count = ft_strlen(res);
		ft_printf("%s", res);
		free(res);
	}
	return (count);
}
