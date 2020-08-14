/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:45:57 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	percent_minus_case(t_format *info)
{
	int		count;

	count = 1;
	ft_putchar('%');
	if (info->flags & FLG_MINUS && info->width != -1)
	{
		while (count < info->width)
		{
			ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

static int	percent_others_case(t_format *info)
{
	int		count;

	count = 1;
	if (info->width != -1)
	{
		while (count < info->width)
		{
			if (info->flags & FLG_ZERO)
				ft_putchar('0');
			else if (!info->flags)
				ft_putchar(' ');
			count++;
		}
	}
	ft_putchar('%');
	return (count);
}

int			percent(t_format *info)
{
	int		count;

	count = 0;
	if (info->flags & FLG_MINUS)
		count = percent_minus_case(info);
	else
		count = percent_others_case(info);
	return (count);
}
