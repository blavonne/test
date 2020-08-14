/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_printing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:19:18 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:15 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	set_base(char specifier)
{
	int		base;

	base = DECIMAL;
	if (ft_strchr("opxX", specifier))
		base = specifier == 'o' ? OCTAL : HEX;
	return (base);
}

static void	print_octal(t_format *info, int base)
{
	char	*res;

	res = NULL;
	if (!info->length[0] || info->length[0] == 'h')
		res = itoa_u(info->z.u, base);
	else if (info->length[0] == 'l' && !info->length[1])
		res = itoa_lu(info->z.lu, base);
	else if (info->length[0] == 'l' && info->length[1])
		res = itoa_llu(info->z.llu, base);
	if (res)
		ft_putstr(res);
	free(res);
}

static void	print_hex(t_format *info, int base)
{
	char	*res;

	res = NULL;
	if (info->specifier == 'p' && !info->z.llu)
		ft_putchar('0');
	else if (!info->length[0] || info->length[0] == 'h')
		res = itoa_u(info->z.u, base);
	else if (info->length[0] == 'l' && !info->length[1])
		res = itoa_lu(info->z.lu, base);
	else if (info->length[0] == 'l' && info->length[1])
		res = itoa_llu(info->z.llu, base);
	info->specifier == 'X' ? ft_str_toupper(res) : ft_str_tolower(res);
	if (res)
		ft_putstr(res);
	free(res);
}

static void	print_decimal(t_format *info)
{
	char	*res;

	res = NULL;
	if (!info->length[0] || info->length[0] == 'h')
		res = itoa_i(info->z.i);
	else if (info->length[0] == 'l' && !info->length[1])
		res = itoa_l(info->z.l);
	else if (info->length[0] == 'l' && info->length[1])
		res = itoa_ll(info->z.ll);
	if (res)
		ft_putstr(res);
	free(res);
}

int			print_arg(t_format *info)
{
	int		base;

	if (!info->z.llu && !info->precision)
		return (0);
	base = set_base(info->specifier);
	if (ft_strchr("di", info->specifier))
		print_decimal(info);
	else if (ft_strchr("uo", info->specifier))
		print_octal(info, base);
	else if (ft_strchr("xXp", info->specifier))
		print_hex(info, base);
	return (1);
}
