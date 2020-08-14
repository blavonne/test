/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractional_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:51:50 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:51:52 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractional.h"

static char		*add_zeros_f(char *tmp, int prec)
{
	char	*zeros;
	char	*res;

	if (!(zeros = ft_strnew(prec - ft_strlen(tmp) + 1)))
		put_errmsg_and_exit('m');
	zeros = ft_memset(zeros, '0', prec - ft_strlen(tmp) + 1);
	res = ft_strjoin(tmp, zeros);
	free(tmp);
	free(zeros);
	return (res);
}

char			*frac_to_str(t_fractional *snake, int prec, unsigned char flags)
{
	int			i;
	char		*res;
	int			j;

	i = 0;
	j = 0;
	if (!(res = ft_strnew(snake->length + 1)))
		put_errmsg_and_exit('m');
	ft_bzero(res, snake->length + 1);
	if (prec || flags & FLG_NBRSIGN)
		res[i++] = '.';
	if (prec)
	{
		while ((j < snake->length && snake->length <= prec) ||\
		(j < prec && snake->length > prec))
			res[i++] = (char)(snake->bigint[j++] + 48);
		if (prec > snake->length)
			res = add_zeros_f(res, prec);
	}
	return (res);
}
