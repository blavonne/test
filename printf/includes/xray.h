/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xray.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:36:42 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 21:36:47 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XRAY_H
# define XRAY_H

/*
** X-ray for exponent, mantissa and sign of long double in memory
*/
typedef union			u_xray
{
	long double			long_double;
	struct
	{
		unsigned char	b0 : 1;
		unsigned char	b1 : 1;
		unsigned char	b2 : 1;
		unsigned char	b3 : 1;
		unsigned char	b4 : 1;
		unsigned char	b5 : 1;
		unsigned char	b6 : 1;
		unsigned char	b7 : 1;
		unsigned char	b8 : 1;
		unsigned char	b9 : 1;
		unsigned char	b10 : 1;
		unsigned char	b11 : 1;
		unsigned char	b12 : 1;
		unsigned char	b13 : 1;
		unsigned char	b14 : 1;
		unsigned char	b15 : 1;
		unsigned char	b16 : 1;
		unsigned char	b17 : 1;
		unsigned char	b18 : 1;
		unsigned char	b19 : 1;
		unsigned char	b20 : 1;
		unsigned char	b21 : 1;
		unsigned char	b22 : 1;
		unsigned char	b23 : 1;
		unsigned char	b24 : 1;
		unsigned char	b25 : 1;
		unsigned char	b26 : 1;
		unsigned char	b27 : 1;
		unsigned char	b28 : 1;
		unsigned char	b29 : 1;
		unsigned char	b30 : 1;
		unsigned char	b31 : 1;
		unsigned char	b32 : 1;
		unsigned char	b33 : 1;
		unsigned char	b34 : 1;
		unsigned char	b35 : 1;
		unsigned char	b36 : 1;
		unsigned char	b37 : 1;
		unsigned char	b38 : 1;
		unsigned char	b39 : 1;
		unsigned char	b40 : 1;
		unsigned char	b41 : 1;
		unsigned char	b42 : 1;
		unsigned char	b43 : 1;
		unsigned char	b44 : 1;
		unsigned char	b45 : 1;
		unsigned char	b46 : 1;
		unsigned char	b47 : 1;
		unsigned char	b48 : 1;
		unsigned char	b49 : 1;
		unsigned char	b50 : 1;
		unsigned char	b51 : 1;
		unsigned char	b52 : 1;
		unsigned char	b53 : 1;
		unsigned char	b54 : 1;
		unsigned char	b55 : 1;
		unsigned char	b56 : 1;
		unsigned char	b57 : 1;
		unsigned char	b58 : 1;
		unsigned char	b59 : 1;
		unsigned char	b60 : 1;
		unsigned char	b61 : 1;
		unsigned char	b62 : 1;
		unsigned char	b63 : 1;
		unsigned int	exponent : 15;
		unsigned int	b79 : 1;
	}					s_parts;
}						t_xray;

#endif
