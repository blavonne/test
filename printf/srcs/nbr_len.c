/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:40:38 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:30 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	nbr_len_l(t_format *info, int base)
{
	int		len;

	len = 1;
	if (info->length[0] == 'l' && !info->length[1] && ft_strchr("di",\
		info->specifier))
		len = nbr_len_int_l(info);
	if (info->length[0] == 'l' && !info->length[1] && ft_strchr("ouxX",\
		info->specifier))
		len = nbr_len_uint_l(info, base);
	if (info->length[0] == 'l' && info->length[1] == 'l' && ft_strchr("di",\
		info->specifier))
		len = nbr_len_int_ll(info);
	if (info->length[0] == 'l' && info->length[1] == 'l' && ft_strchr("ouxXp",\
		info->specifier))
		len = nbr_len_uint_ll(info, base);
	return (len);
}

int			nbr_len(t_format *info)
{
	int		base;
	int		len;

	base = DECIMAL;
	len = 1;
	if (ft_strchr("opxX", info->specifier))
		base = info->specifier == 'o' ? OCTAL : HEX;
	if ((!info->length[0] || info->length[0] == 'h') && ft_strchr("di",\
	info->specifier))
		len = nbr_len_int(info);
	if ((!info->length[0] || info->length[0] == 'h') && ft_strchr("ouxX",\
	info->specifier))
		len = nbr_len_uint(info, base);
	if (info->length[0] == 'l')
		len = nbr_len_l(info, base);
	return (len);
}
