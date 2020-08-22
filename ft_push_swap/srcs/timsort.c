/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:37:55 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:41:28 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ========MINRUN========
** get 6 highest bits of N (64 for int64) and add 1 if there is at least one
** not zeroed element in lowest bits
*/

static int		get_minrun(int size)
{
	int r;

	r = 0;
	while (size >= 64)
	{
		r |= size & 1;
		size >>= 1;
	}
	return (size + r);
}

/*
** ========INITIALIZE_MAP========
** map contains pairs "index minrun-begin - minrun-size"
** map always contains more than necessary zeroed elements
*/

static t_map	*initialize_map(int size, int minrun)
{
	t_map	*map;
	int		len;

	len = size / minrun + 1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->size = (int *)malloc(sizeof(int) * (len + 1))))
	{
		free(map);
		return (NULL);
	}
	if (!(map->begin = (int *)malloc(sizeof(int) * (len + 1))))
	{
		free(map->size);
		free(map);
		return (NULL);
	}
	map->size = ft_memset(map->size, 0, sizeof(int) * (len + 1));
	map->begin = ft_memset(map->begin, 0, sizeof(int) * (len + 1));
	map->beg = 0;
	map->end = 0;
	return (map);
}

static int		set_end(int size, int minrun, int *arr, int end)
{
	if (end + 1 < size && end + 1 < minrun && arr[end] < arr[end + 1])
		while (end + 1 < size && end + 1 < minrun && arr[end] <\
			arr[end + 1])
			end++;
	else if (end + 1 < size && end + 1 < minrun && arr[end] > arr[end + 1])
		while (end + 1 < size && end + 1 < minrun && arr[end] >\
			arr[end + 1])
			end++;
	return (end);
}

int				*timsort(int *arr, int size)
{
	t_map	*map;
	int		minrun;
	int		i;

	minrun = get_minrun(size);
	i = 0;
	if (!(map = initialize_map(size, minrun)))
		return (NULL);
	while (map->end < size)
	{
		map->end = set_end(size, minrun, arr, map->end);
		if (map->end - map->beg + 1 < minrun)
		{
			map->end = map->beg + minrun > size ? size - 1 : minrun - 1 +\
			map->beg;
			arr = insertion_sort(arr, map);
		}
		map = set_map(map, i);
		i++;
	}
	arr = merge(arr, &map);
	destroy_map(&map);
	return (arr);
}
