#include "checker.h"

static int	*get_arr(t_stack **a, int size)
{
	t_stack	*ptr;
	int		*arr;
	int		i;

	if (!(arr = (int *)malloc((sizeof(int) * size))))
		clean_exit(a, 'm');
	i = 0;
	ptr = (*a);
	while (ptr && i < size)
	{
		arr[i] = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (arr);
}

static int	get_middle(int *arr, int size)
{
	if ((arr = timsort(arr, size)))
		return (arr[size / 2]);
	else
		return (-1);
}

char		**get_commands(t_stack **a, t_stack **b, int size)
{
	char	**cmd;
	int		middle_val;
	int		*chunk;
	int		*arr;

	arr = get_arr(a, size);
	middle_val = get_middle(arr, size);
	if (middle_val == -1)
		clean_exit(a, 'm');
	ft_printf("Middle is = %d\n", middle_val);
	return (NULL);
}
