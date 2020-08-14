#include "checker.h"

/*
** minrun
** берём старшие 6 бит из N и добавляем единицу,
** если в оставшихся младших битах есть хотя бы один ненулевой.
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

static t_map	*initialize_map(int size, int minrun)
{
	t_map	*map;
	int		len;

	len = size / minrun + 1;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->size = (int *)malloc(sizeof(int) * len)))
	{
		free(map);
		return (NULL);
	}
	if (!(map->begin = (int *)malloc(sizeof(int) * len)))
	{
		free(map->size);
		free(map);
		return (NULL);
	}
	map->size = ft_memset(map->size, 0, sizeof(int) * len);
	map->begin = ft_memset(map->begin, 0, sizeof(int) * len);
	return (map);
}

int				*insertion_sort(int *arr, int begin, int end)
{
	int		x;
	int		j;

	while (begin + 1 < end)
	{
		x = arr[begin + 1];
		j = begin + 1;
		while (j > 0 && arr[j - 1] > x)
		{
			ft_swap(&arr[j], &arr[j - 1]);
			j--;
		}
		arr[j] = x;
		begin++;
	}
	return (arr);
}

int				*merge_sort(int *x, int *y, int x_size, int y_size)
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
	{
		if (temp[i] < y[j])
			x[k++] = temp[i++];
		else
			x[k++] = y[j++];
	}
	if (i == x_size)
		while (j < y_size)
			x[k++] = y[j++];
	else if (j == y_size)
		while (i < x_size)
			x[k++] = temp[i++];
	free(temp);
	return (x);
}

int				*merge2(int *arr, t_map **map, int left, int right)
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
		(*map)->size[i] = (*map)->size[i + 1];
		(*map)->begin[i] = (*map)->begin[i + 1];
		i++;
	}
	return (arr);
}

int				*merge(int *arr, t_map **map, int size)
{
	int		i;
	int		x;
	int		y;
	int		z;

	i = 1;//Y
	x = (*map)->size[i - 1] ? (*map)->size[i - 1] : 0;
	y = x && (*map)->size[i] ? (*map)->size[i] : 0;
	z = y && (*map)->size[i + 1] ? (*map)->size[i + 1] : 0;
	while ((*map)->size[1])
	{
		while (x && y && z && (x > y + z) && (y > z) && (i + 1 < size))
		{
			i++;//нашла подмассив i, который можно мёрджить	X > Y + Z, Y > Z
			x = (*map)->size[i - 1];
			y = (*map)->size[i];
			z = (*map)->size[i + 1];
		}
		if (x && z && x > z)
			arr = merge2(arr, map, i, i + 1);
		else if (x && !z || x < z)
			arr = merge2(arr, map, i - 1, i);
		if (!arr)
			return (NULL);
	}
	return (arr);
}

int				*timesort(int *arr, int size)
{
	t_map	*map;
	int		minrun;
	int		begin;
	int		end;

	int		i;

	minrun = get_minrun(size);
	begin = 0;
	end = 0;
	i = 0;
	if (!(map = initialize_map(size, minrun)))
		return (NULL);
	while (end < size)
	{
		if (end + 1 < size && end + 1 < minrun && arr[end] < arr[end + 1])
			while (end + 1 < size && end + 1 < minrun && arr[end] <\
			arr[end + 1])
				end++;
		else if (end + 1 < size && end + 1 < minrun && arr[end] > arr[end + 1])
			while (end + 1 < size && end + 1 < minrun && arr[end] >\
			arr[end + 1])
				end++;
		// end указывает на последний отсортированный элемент
		if (end - begin + 1 < minrun)
		{
			end == size - 1 ? 0 : (end = minrun - 1 + begin);
			arr = insertion_sort(arr, begin, end);
		}
		map->begin[i] = begin;
		map->size[i] = end - begin + 1;
		i++;
		begin = end + 1;
		end = begin;
	}
	if (!(arr = merge(arr, &map, size)))
		return (NULL);

	// end указывает на последний отсортиванный элемент или на конец минран
	return (arr);
}