/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:02:38 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	print_string(t_format *info, char *arg)
{
	if (arg)
	{
		if (info->precision != -1 && info->precision < (int)ft_strlen(arg))
			write(1, arg, (unsigned)info->precision);
		else
			ft_putstr(arg);
	}
	else
	{
		if (info->precision >= STR_NULL_LEN || info->precision == -1)
			ft_putstr("(null)");
		else
			write(1, "(null)", (unsigned)info->precision);
	}
}

static int	str_len(t_format *info, char *arg)
{
	int		count;

	count = 0;
	if (arg)
	{
		if (info->precision != -1)
		{
			if (info->precision < (int)ft_strlen(arg))
				count = info->precision;
			else
				count = (int)ft_strlen(arg);
		}
		if (info->precision == -1)
			count = (int)ft_strlen(arg);
	}
	else
	{
		if (info->precision >= STR_NULL_LEN || info->precision == -1)
			count = STR_NULL_LEN;
		else
			count = info->precision;
	}
	return (count);
}

int			string_case(t_format *info, char *arg)
{
	int		count;
	char	c;

	c = (info->flags & FLG_ZERO) ? '0' : ' ';
	count = str_len(info, arg);
	if (info->flags & FLG_MINUS)
	{
		print_string(info, arg);
		while (count++ < info->width)
			ft_putchar(' ');
	}
	else
	{
		while (count++ < info->width)
			ft_putchar(c);
		print_string(info, arg);
	}
	count--;
	return (count);
}

int			char_case(t_format *info, unsigned char arg)
{
	int		count;

	count = 0;
	if (info->flags & FLG_MINUS)
	{
		ft_putchar((char)arg);
		count++;
		while (count < info->width)
		{
			ft_putchar(' ');
			count++;
		}
	}
	else
	{
		count++;
		while (count < info->width)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar((char)arg);
	}
	return (count);
}
