/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:43:25 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 18:00:07 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	parse_text(char *format, int *i, int *count)
{
	while (format[*i] && format[*i] != '%')
	{
		write(1, &format[*i], 1);
		(*count)++;
		(*i)++;
	}
	if (format[*i] == '%')
		(*i)++;
}

void	parse_width(char *format, int *i, t_format *info)
{
	if (format[*i] == '*')
	{
		info->width = READ_ARG;
		(*i)++;
		return ;
	}
	while (ft_isdigit(format[*i]))
	{
		if (info->width == -1)
			info->width = format[*i] - 48;
		else
		{
			info->width *= 10;
			info->width += format[*i] - 48;
		}
		(*i)++;
	}
}

void	parse_prec(char *format, int *i, t_format *info)
{
	if (format[*i] && format[*i] == '.' && format[(*i) + 1])
	{
		(*i)++;
		if (!ft_isdigit(format[*i]) && format[*i] != '*')
			info->precision = 0;
		else if (format[*i] == '*')
		{
			info->precision = READ_ARG;
			(*i)++;
		}
		else
			while (ft_isdigit(format[*i]))
			{
				if (info->precision == -1)
					info->precision = format[*i] - 48;
				else
				{
					info->precision *= 10;
					info->precision += format[*i] - 48;
				}
				(*i)++;
			}
	}
}

void	parse_length(char *format, int *i, t_format *info)
{
	if (format[*i] && ft_strchr("hlLjzt", format[*i]))
	{
		if (format[*i] == 'l' || format[*i] == 'h')
		{
			info->length[0] = (format[*i] == 'l') ? 'l' : 'h';
			(*i)++;
			if (format[*i] && format[(*i) - 1] == 'l' && format[*i] == 'l')
			{
				info->length[1] = 'l';
				(*i)++;
			}
			else if (format[*i] && format[(*i) - 1] == 'h' && format[*i] == 'h')
			{
				info->length[1] = 'h';
				(*i)++;
			}
		}
		else if (ft_strchr("Ljzt", format[*i]) && !info->length[0])
			info->length[0] = format[(*i)++];
	}
}

int		parse_type(char *format, int *i, t_format *info)
{
	if (format[*i] && ft_strchr("diouxXeEfFgGaAcspnm%", format[*i])\
	&& !info->specifier)
	{
		info->specifier = format[*i];
		(*i)++;
		return (1);
	}
	return (0);
}
