/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:52:38 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:52:40 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "integral.h"

static char			*add_zeros(char *s, int count)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (!(res = ft_strnew(count)))
		exit(-1);
	while (i < count - len)
	{
		res[i] = '0';
		i++;
	}
	while (i < count)
		res[i++] = s[j++];
	free(s);
	return (res);
}

static char			*zero_integral(void)
{
	char	*buf;

	if (!(buf = ft_strnew(1)))
		put_errmsg_and_exit('m');
	buf[0] = '0';
	return (buf);
}

char				*integral_to_str(t_integral *one)
{
	int			i;
	char		*buf;
	char		*tmp;

	one->length = set_len_integral(one);
	i = one->length - 1;
	if (!one->length && (buf = zero_integral()))
		return (buf);
	if (!(buf = ft_strnew(one->length * 9)))
		put_errmsg_and_exit('m');
	ft_bzero(buf, one->length * 9);
	while (i >= 0)
	{
		tmp = itoa_ll(one->bigint[i]);
		if (i && i != one->length - 1 && one->bigint[i] && ft_strlen(tmp)\
		!= COUNT_DIGITS)
			tmp = add_zeros(tmp, COUNT_DIGITS);
		buf = ft_strcat(buf, tmp);
		free(tmp);
		i--;
	}
	return (buf);
}
