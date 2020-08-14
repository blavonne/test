/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:47:51 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:35 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		pointer(t_format *info, va_list *arg)
{
	int		count;

	count = 0;
	info->z.llu = (unsigned long long)va_arg(*arg, void*);
	info->length[0] = 'l';
	info->length[1] = 'l';
	info->flags = info->flags | FLG_NBRSIGN;
	if (info->flags & FLG_MINUS)
		count = flg_minus_case(info);
	else if (info->flags & FLG_ZERO)
		count = flg_zero_case(info);
	else
		count = flg_others_case(info);
	return (count);
}
