/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:49:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:43 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			initialize_format_struct(t_format *info)
{
	info->flags = FLG_NONE;
	info->width = -1;
	info->precision = -1;
	info->length[0] = FLG_NONE;
	info->length[1] = FLG_NONE;
	info->length[2] = '\0';
	info->specifier = 0;
	info->z.llu = 0;
	ft_bzero(info->r.mantissa, 65);
}

static void		start_parser(char *format, t_format *info, int *i, int *count)
{
	parse_text(format, i, count);
	parse_flags(format, i, info);
	parse_width(format, i, info);
	parse_prec(format, i, info);
	parse_length(format, i, info);
	parse_type(format, i, info);
}

int				ft_printf(char *format, ...)
{
	int			count;
	int			i;
	t_format	info;
	va_list		arg;

	count = 0;
	i = 0;
	va_start(arg, format);
	initialize_format_struct(&info);
	while (format[i])
	{
		start_parser(format, &info, &i, &count);
		if (info.specifier)
		{
			check_info(&info, &arg);
			count += push_to_processor(&info, &arg);
			initialize_format_struct(&info);
		}
	}
	va_end(arg);
	return (count);
}
