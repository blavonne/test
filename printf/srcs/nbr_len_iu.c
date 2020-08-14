/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_len_iu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:23:17 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:59:39 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		nbr_len_int(t_format *info)
{
	int		temp;
	int		len;
	char	*res;

	res = NULL;
	temp = info->z.i;
	if (!(res = itoa_i(temp)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}

int		nbr_len_uint(t_format *info, int base)
{
	unsigned int	temp;
	int				len;
	char			*res;

	res = NULL;
	temp = info->z.u;
	if (!(res = itoa_u(temp, base)))
		put_errmsg_and_exit('m');
	len = (int)ft_strlen(res);
	free(res);
	return (len);
}
