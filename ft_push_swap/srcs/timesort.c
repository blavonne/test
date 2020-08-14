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
	return (map);
}

int				*insertion_sort(int *arr, int begin, int end)
{
	int		x;
	int		j;
	int		*ptr;

	ptr = &arr[begin];
	end = end - begin;
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
		ft_swap(&(*map)->size[i], &(*map)->size[i + 1]);
		ft_swap(&(*map)->begin[i], &(*map)->begin[i + 1]);
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
		else if (x && !z || x <= z)
			arr = merge2(arr, map, i - 1, i);
		if (!arr)
			return (NULL);
	}
	return (arr);
}

void			print_arr(int *arr, int size)
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

void			check_ord(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				ft_printf("KO\n");
				return ;
			}
			j++;
		}
		i++;
	}
	ft_printf("OK\n");
}

int				*timesort(int *arr, int size)
{
	t_map	*map;
	int		minrun;
	int		begin;
	int		end;
	int		i;

	int		temp[] = {86, 333, 125, 97, 71, 248, 345, 350, 431, 220, 239, 464, 168, 14, 177, 89, 405, 437, 325, 43, 326, 243, 107, 487, 493, 195, 202, 499, 142, 368, 77, 418, 196, 150, 61, 214, 423, 454, 324, 311, 415, 397, 67, 410, 228, 185, 190, 355, 173, 307, 172, 49, 498, 398, 375, 282, 280, 390, 181, 146, 360, 207, 23, 463, 133, 356, 435, 101, 3, 119, 409, 335, 54, 218, 211, 249, 32, 384, 460, 294, 197, 297, 176, 260, 339, 379, 182, 491, 175, 262, 359, 276, 287, 0, 444, 34, 26, 348, 475, 258, 373, 151, 281, 149, 372, 383, 85, 183, 308, 450, 259, 93, 141, 447, 367, 11, 163, 236, 88, 364, 465, 225, 68, 152, 332, 70, 206, 486, 382, 25, 443, 344, 31, 268, 78, 414, 436, 452, 470, 269, 314, 481, 192, 490, 79, 64, 315, 169, 90, 256, 374, 55, 316, 413, 349, 334, 488, 231, 461, 399, 476, 95, 338, 115, 200, 65, 38, 278, 162, 263, 112, 203, 12, 179, 295, 385, 434, 87, 226, 69, 420, 458, 496, 483, 340, 164, 274, 209};
	size = 188;
	arr = temp;
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
		// end указывает на первый не отсортированный элемент
		if (end - begin + 1 < minrun)
		{
			end = minrun - 1 + begin;
			end == size ? end-- : 0;
			arr = insertion_sort(arr, begin, end);
			print_arr(arr, size);
		}
		map->begin[i] = begin;
		map->size[i] = end - begin + 1;
		i++;
		begin = end + 1;
		end = begin + 1;
	}
	if (!(arr = merge(arr, &map, size)))
		return (NULL);
	print_arr(arr, size);
	check_ord(arr, size);
	// end указывает на последний отсортиванный элемент или на конец минран
	return (arr);
}