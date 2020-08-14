/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:59:29 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:22 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		chars(t_format *info, va_list *arg)
{
	unsigned char	temp_c;
	int				count;
	char			*temp_s;

	count = 0;
	temp_s = NULL;
	if (info->specifier == 'c' && !info->length[0])
	{
		temp_c = (unsigned char)va_arg(*arg, int);
		count = char_case(info, temp_c);
	}
	if (info->specifier == 's' && !info->length[0])
	{
		temp_s = va_arg(*arg, char*);
		count = string_case(info, temp_s);
	}
	return (count);
}
