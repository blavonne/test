/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:53:00 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:53:03 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTIONAL_H
# define FRACTIONAL_H

/*
** Secondary includes
*/
# include "printf.h"

/*
** Size of fractional bigint
*/

# define TAIL_SIZE		1200

/*
** Definitions
*/
typedef struct	s_fractional
{
	int			bigint[TAIL_SIZE];
	int			length;
}				t_fractional;

/*
** Fractional basic
*/
t_fractional	initialize_frac(t_fractional *snake);
int				set_len_frac(t_fractional *snake);
void			normalize_frac(t_fractional *snake);

/*
** Fractional math
*/
t_fractional	frac_five_power(t_fractional *snake, int power);
t_fractional	addition_frac(t_fractional *one, t_fractional *two);

/*
** Get fractional part and convert to string
*/
t_fractional	get_fractional(char *mantissa, int exp);
char			*frac_to_str(t_fractional *snake, int prec,\
				unsigned char flags);

#endif
