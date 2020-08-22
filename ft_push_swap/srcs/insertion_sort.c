/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:26:35 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:26:42 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ========INSERTION_SORT========
** swaps current element with previous until they are wrong located
*/

int				*insertion_sort(int *arr, t_map *map)
{
	int		x;
	int		j;
	int		*ptr;
	int		begin;
	int		end;

	ptr = &arr[map->beg];
	end = map->end - map->beg;
	begin = 0;
	while (begin <= end)
	{
		x = ptr[begin];
		j = begin;
		while (j > 0 && ptr[j - 1] > x)
		{
			ft_swap(&ptr[j], &ptr[j - 1]);
			j--;
		}
		ptr[j] = x;
		begin++;
	}
	return (arr);
}
