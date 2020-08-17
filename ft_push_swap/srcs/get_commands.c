#include "checker.h"

static int		*get_arr(t_stack **a, int size)
{
	t_stack	*ptr;
	int		*arr;
	int		i;

	if (!(arr = (int *)malloc((sizeof(int) * size))))
		clean_and_exit(a, 0, 0, 'm');
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

static int		get_middle(int *arr, int size)
{
	if ((arr = timsort(arr, size)))
		return (arr[size / 2]);
	else
		return (-1);
}

int				check_mid(t_stack *a, int middle)
{
	while (a)
	{
		if (a->value < middle)
			return (1);
		a = a->next;
	}
	return (0);
}

int				set_size(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_vectors		*get_commands(t_stack **a, t_stack **b, int size)
{
	int				middle_val;
	int				*arr;
	t_stack			*ptr;
	t_vectors		*cmd;

	if (!(cmd = create_vectors(VECTOR_SIZE)))
		clean_and_exit(a, b, 0, 'm');
	while ((*a) && (*a)->next && (*a)->next->next && !(check_order((*a), 0)))
	{
		arr = get_arr(a, size);
		middle_val = get_middle(arr, size);
		free(arr);
		if (middle_val == -1)
			clean_and_exit(a, b, 0, 'm');
		ft_printf("Middle is = %d\n", middle_val);
		ptr = (*a);
		while (check_mid((*a), middle_val))
		{
			while (ptr && ptr->value < middle_val)
			{
				run_command("pb", a, b);
				if (!push_in_vector(&cmd->cmd, PB, sizeof(char)))
					clean_and_exit(a, b, &cmd, 'm');
				ptr = (*a);
			}
			ft_printf("This operation is default.\n");
			run_command("rra", a, b);
			ptr = (*a);
			while (ptr && ptr->value < middle_val)
			{
				if (!push_in_vector(&cmd->cmd, RRA, sizeof(char)))
					clean_and_exit(a, b, &cmd, 'm');
				run_command("pb", a, b);
				if (!push_in_vector(&cmd->cmd, PB, sizeof(char)))
					clean_and_exit(a, b, &cmd, 'm');
				run_command("rra", a, b);
				ptr = (*a);
			}
			ft_printf("This operation is default.\n");
			run_command("ra", a, b);
			ptr = (*a);
			while (ptr && check_mid(*a, middle_val) && ptr->value >= middle_val)
			{
				run_command("ra", a, b);
				if (!push_in_vector(&cmd->cmd, RA, sizeof(char)))
					clean_and_exit(a, b, &cmd, 'm');
				ptr = (*a);
			}
		}
		ft_printf("====Result of moving in b-stack:====\n");
		print(*a, *b);
		size = set_size(*a);
	}
	if ((*a) && (*a)->next && !(*a)->next->next && (*a)->value >\
		(*a)->next->value)
	{
		run_command("sa", a, b);
		if (!push_in_vector(&cmd->cmd, SA, sizeof(char)))
			clean_and_exit(a, b, &cmd, 'm');
	}
	return (cmd);
}
