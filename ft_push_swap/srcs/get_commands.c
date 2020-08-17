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
	while (arr && ptr && i < size)
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

int			check_status(t_stack *a, int middle)
{
	while (a)
	{
		if (a->value < middle)
			return (1);
		a = a->next;
	}
	return (0);
}

char		**add_command(char ***cmd, char *action, t_stack **a, t_stack **b)
{
	if (!(*cmd))
	{
		if (!((*cmd) = (char **)malloc(sizeof(char *) * (CMD_COUNT + 1))))
		{
			destroy_stack(a);
			clean_exit(b, 'm');
		}
		(*cmd)[CMD_COUNT] = NULL;
	}
	return (*cmd);
}

char		**get_commands(t_stack **a, t_stack **b, int size)
{
	char	**cmd;
	int		middle_val;
	int		*chunk;
	int		*arr;
	t_stack	*ptr;

	arr = get_arr(a, size);
	middle_val = get_middle(arr, size);
	if (middle_val == -1)
		clean_exit(a, 'm');
	ft_printf("Middle is = %d\n", middle_val);
	free(arr);
	ptr = (*a);
	cmd = NULL;
	while (check_status((*a), middle_val))
	{
		while (ptr && ptr->value < middle_val)
		{
			run_command("pb", a, b);
			cmd = add_command(&cmd, "pb", a, b);
			ptr = (*a);
		}
		run_command("rra", a, b);
		ptr = (*a);
		while (ptr && ptr->value < middle_val)
		{
			run_command("pb", a, b);
			cmd = add_command(&cmd, "pb", a, b);
			run_command("rra", a, b);
			cmd = add_command(&cmd, "rra", a, b);
			ptr = (*a);
		}
		run_command("ra", a, b);
		ptr = (*a);
		while (ptr && check_status(*a, middle_val) && ptr->value >= middle_val)
		{
			run_command("ra", a, b);
			cmd = add_command(&cmd, "ra", a, b);
			ptr = (*a);
		}
	}
	print(*a, *b);
	return (NULL);
}
