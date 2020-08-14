/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:53:07 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:53:09 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_H
# define INTEGRAL_H

/*
** Secondary includes
*/
# include "printf.h"

/*
** Count of digits in arr and size of integral bigint
*/
# define BASE			1000000000
# define SIZE			549
# define COUNT_DIGITS	9

/*
** Definitions
*/
typedef struct		s_power
{
	int				full;
	int				rest;
}					t_power;

typedef struct		s_integral
{
	long long int	bigint[SIZE];
	int				length;
}					t_integral;

/*
** Integral math
*/
t_integral			multiply(t_integral *one, t_integral *two);
t_integral			addition(t_integral *one, t_integral *two);
t_integral			substraction(t_integral *one, t_integral *two);
t_integral			division_by_nbr(t_integral *res, int divider);
t_integral			multiply_by_nbr(t_integral *elephant, long long fly);
t_integral			add_nbr(t_integral *elephant, long long fly);

/*
** Integral basic
*/
t_integral			create_integral(int base, int exp);
t_integral			initialize_integral(t_integral *elephant);
void				normalize_integral(t_integral *elephant);
int					set_len_integral(t_integral *elephant);

/*
** Get integral part and convert to string
*/
t_integral			get_integral(int exp, char *mantissa);
char				*integral_to_str(t_integral *one);

#endif
