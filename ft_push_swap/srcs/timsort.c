#include "checker.h"

static void			check_ord(int *arr, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] >= arr[j])
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
	return (map);
}

/*
** ========INSERTION_SORT========
** swap current element with previous until they are wrong located
*/

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

int				*merge_sort(int *x, int *y, int x_size, int y_size)
{
	int		*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;

//	ft_printf("===Merge sort===\n");
//	ft_printf("x-array: ");
//	print_arr(x, x_size);
//	ft_printf("y-array: ");
//	print_arr(y, y_size);
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
//	ft_printf("Merge res: ");
//	print_arr(arr, (*map)->size[left]);
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

static int		*merge(int *arr, t_map **map, int size)
{
	int		i;
	int		x;
	int		y;
	int		z;

	i = 1;
	while ((*map)->size[i])
	{
		x = (*map)->size[i - 1] ? (*map)->size[i - 1] : 0;
		y = x && (*map)->size[i] ? (*map)->size[i] : 0;
		z = y && (*map)->size[i + 1] ? (*map)->size[i + 1] : 0;
		if (x && y && z && (x > y + z) && (y > z))
			i++;
		else if (x && z && x > z)
		{
			arr = merge2(arr, map, i, i + 1);
			ft_printf("Merge status: ");
			check_ord(&arr[(*map)->begin[i]], (*map)->size[i]);
			i = 1;
		}
		else if (x && !z || x <= z)
		{
			arr = merge2(arr, map, i - 1, i);
			ft_printf("Merge status: ");
			check_ord(&arr[(*map)->begin[i - 1]], (*map)->size[i - 1]);
			i = 1;
		}
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

int				*timsort(int *arr, int size)
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
		if (end - begin + 1 < minrun)
		{
			end = begin + minrun > size ? size - 1 : minrun - 1 + begin;
			arr = insertion_sort(arr, begin, end);
		}
		map->begin[i] = begin;
		map->size[i] = end - begin + 1;
		i++;
		begin = end + 1;
		end = begin + 1;
	}
	free(map->size);
	free(map->begin);
	free(map);
	if (!(arr = merge(arr, &map, size)))
	{
		free(arr);
		return (NULL);
	}
	ft_printf("Array after sort: ");
	print_arr(arr, size);//потом убрать
	ft_printf("Sort status: ");
	check_ord(arr, size);//убрать потом
	return (arr);
}