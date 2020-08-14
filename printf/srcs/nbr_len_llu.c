/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:26:40 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:48 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		nbr_len_int_ll(t_format *info)
{
	long long	temp;
	int			len;
	char		*res;

	res = NULL;
	temp = info->z.ll;
	if (!(res = itoa_ll(temp)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}

int		nbr_len_uint_ll(t_format *info, int base)
{
	unsigned long long	temp;
	int					len;
	char				*res;

	res = NULL;
	temp = info->z.llu;
	if (!(res = itoa_llu(temp, base)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}
