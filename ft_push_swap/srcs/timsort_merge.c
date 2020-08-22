/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timsort_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:36:01 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:36:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ==========MERGE_SORT==========
** in this func we create temp-array and copy left-array (x) in temp
** in memory wa have x[0]x[1]...x[x_size - 1]y[0]y[1]...y[y_size - 1]
** so we compare temp-value with y-value and put the smallest into x-array
** until one of y-array or temp-array is off
** then we copy into x-array the other values of array, which is not off
** do not forget to free temp!
** now x+y-array is sorted
*/

static int		*merge_sort(int *x, int *y, int x_size, int y_size)
{
	int		*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!(temp = (int *)malloc(sizeof(int) * x_size)))
		return (NULL);
	temp = ft_memcpy(temp, x, sizeof(int) * x_size);
	while (i < x_size && j < y_size)
		if (temp[i] < y[j])
			x[k++] = temp[i++];
		else
			x[k++] = y[j++];
	if (i == x_size)
		while (j < y_size)
			x[k++] = y[j++];
	else if (j == y_size)
		while (i < x_size)
			x[k++] = temp[i++];
	free(temp);
	return (x);
}

/*
** ==========MERGE2==========
** in this func we run to merge a pair of minruns, which are sequentially
** located in memory and after this we update map
*/

static int		*merge2(int *arr, t_map **map, int left, int right)
{
	int		i;
	int		*x;
	int		*y;

	x = &arr[(*map)->begin[left]];
	y = &arr[(*map)->begin[right]];
	if (!(x = merge_sort(x, y, (*map)->size[left], (*map)->size[right])))
		return (NULL);
	(*map)->size[left] += (*map)->size[right];
	(*map)->size[right] = 0;
	(*map)->begin[right] = 0;
	i = right;
	while ((*map)->size[i + 1])
	{
		ft_swap(&(*map)->size[i], &(*map)->size[i + 1]);
		ft_swap(&(*map)->begin[i], &(*map)->begin[i + 1]);
		i++;
	}
	return (arr);
}

/*
** ==========MERGE==========
** map = pairs of begin_minrun_index + minrun_size, x, y, z = minrun's_size
** x - the first pair, y - the second, z - the third
** we should merge +- equal by size arrays (minruns) at first
** also they must be only neighbours
** we can not merge, if X > Y + Z && Y > Z
** in this function we choose pair minruns to merge
*/

int				*merge(int *arr, t_map **map)
{
	int		i;
	int		x;
	int		y;
	int		z;

	i = 1;
	while (arr && (*map)->size[i])
	{
		x = (*map)->size[i - 1] ? (*map)->size[i - 1] : 0;
		y = x && (*map)->size[i] ? (*map)->size[i] : 0;
		z = y && (*map)->size[i + 1] ? (*map)->size[i + 1] : 0;
		if (x && y && z && (x > y + z) && (y > z))
			i++;
		else if ((x && z && x > z) || ((x && !z) || (x <= z)))
		{
			arr = (x && z && x > z) ? merge2(arr, map, i, i + 1) :\
			merge2(arr, map, i - 1, i);
			i = 1;
		}
	}
	return (arr);
}
