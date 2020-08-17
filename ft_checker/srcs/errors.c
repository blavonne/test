/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 01:05:04 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/06 17:58:36 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	put_errmsg_and_exit(char type)
{
	if (type == 'm')
		ft_putstr_fd("Error m.\n", 2);
	if (type == 'd')
		ft_putstr_fd("Error d.\n", 2);
	if (type == 'r')
		ft_putstr_fd("Error r.\n", 2);
	if (type == 'h')
		ft_putstr_fd("Trying to destroy not head!\n", 2);
	type == 0 ? exit(0) : exit(1);
}
