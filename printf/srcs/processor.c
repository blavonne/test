/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:51:30 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		push_to_processor(t_format *info, va_list *arg)
{
	if (ft_strchr("diouxX", info->specifier))
		return (integer(info, arg));
	if (ft_strchr("sc", info->specifier))
		return (chars(info, arg));
	if (info->specifier == '%')
		return (percent(info));
	if (info->specifier == 'p')
		return (pointer(info, arg));
	if (info->specifier == 'f')
		return (floats(info, arg));
	return (0);
}
