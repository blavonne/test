#include "checker.h"

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
