#include "checker.h"

void			print_arr(int *arr, int size)//del
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_printf("[%i]%-3d ", i, arr[i]);
		i++;
	}
	ft_printf("\n");
}

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

static t_map	*set_map(t_map *map, int i)
{
	map->begin[i] = map->beg;
	map->size[i] = map->end - map->beg + 1;
	map->beg = map->end + 1;
	map->end = map->beg + 1;
	return (map);
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
	ft_printf("Array after sort: ");
	print_arr(arr, size);//потом убрать
	ft_printf("Sort status: ");
	check_ord(arr, size);//убрать потом
	return (arr);
}
