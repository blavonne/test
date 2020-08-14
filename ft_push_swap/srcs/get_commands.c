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
	while (arr && i < size)
	{
		arr[i] = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (arr);
}

static int	get_middle(int *arr, int size)
{
	arr = timesort(arr);
	return (arr[size - 1]);
}

char		**get_commands(t_stack **a, t_stack **b, int size)
{
	char	**cmd;
	int		middle_val;
	int		*chunk;
	int		*arr;

	arr = get_arr(a, size);
	middle_val = get_middle(arr, size);

}
