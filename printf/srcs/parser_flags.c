/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:45:10 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	set_flag(char c, t_format *info)
{
	if (c == ' ')
		info->flags = info->flags | FLG_SPACE;
	else if (c == '0')
		info->flags = info->flags | FLG_ZERO;
	else if (c == '#')
		info->flags = info->flags | FLG_NBRSIGN;
	else if (c == '+')
		info->flags = info->flags | FLG_PLUS;
	else if (c == '-')
		info->flags = info->flags | FLG_MINUS;
	if ((info->flags & FLG_ZERO) && (info->flags & FLG_MINUS))
		info->flags = info->flags & (unsigned char)(~FLG_ZERO);
	if ((info->flags & FLG_PLUS) && (info->flags & FLG_SPACE))
		info->flags = info->flags & (unsigned char)(~FLG_SPACE);
}

void	parse_flags(char *format, int *i, t_format *info)
{
	if (format[*i] && ft_strchr("0#-+ ", format[*i]))
	{
		while (format[*i] && ft_strchr("0#-+ ", format[*i]))
		{
			set_flag(format[*i], info);
			(*i)++;
		}
	}
}
