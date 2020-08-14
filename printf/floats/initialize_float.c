/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:52:08 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:52:10 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void				set_mantissa3(int *i, t_float *res, t_xray *arg)
{
	res->mantissa[(*i)++] = (char)(arg->s_parts.b20 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b19 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b18 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b17 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b16 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b15 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b14 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b13 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b12 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b11 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b10 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b9 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b8 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b7 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b6 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b5 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b4 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b3 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b2 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b1 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b0 + 48);
}

static void				set_mantissa2(int *i, t_float *res, t_xray *arg)
{
	res->mantissa[(*i)++] = (char)(arg->s_parts.b43 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b42 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b41 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b40 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b39 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b38 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b37 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b36 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b35 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b34 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b33 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b32 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b31 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b30 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b29 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b28 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b27 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b26 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b25 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b24 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b23 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b22 + 48);
	res->mantissa[(*i)++] = (char)(arg->s_parts.b21 + 48);
	set_mantissa3(i, res, arg);
}

static void				set_mantissa(t_xray *arg, t_float *res)
{
	int			i;

	i = 0;
	res->mantissa[i++] = (char)(arg->s_parts.b63 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b62 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b61 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b60 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b59 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b58 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b57 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b56 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b55 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b54 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b53 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b52 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b51 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b50 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b49 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b48 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b47 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b46 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b45 + 48);
	res->mantissa[i++] = (char)(arg->s_parts.b44 + 48);
	set_mantissa2(&i, res, arg);
}

t_float					initialize_float(long double arg)
{
	t_xray		tmp;
	t_float		res;

	tmp.long_double = arg;
	res.sign = (char)tmp.s_parts.b79;
	res.exponent = (int)(tmp.s_parts.exponent - (unsigned)16383);
	ft_bzero(res.mantissa, 65);
	set_mantissa(&tmp, &res);
	return (res);
}
