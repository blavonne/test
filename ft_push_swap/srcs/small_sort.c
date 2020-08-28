#include "push_swap.h"

int		try_s(t_stack **a, t_stack **b, t_info **info)
{
	t_stack *copy;

	copy = copy_stack(*a);
	copy ? 0 : clean_and_exit(a, b, info, 'm');
	run_command("sa", &copy, 0);
	if (ft_isslice(copy))
	{
		run_command("sa", a, b);
		if (!(push_in_vector(&(*info)->cmd_c, SA, sizeof(char))))
			clean_and_exit(a, b, info, 'm');
		destroy_stack(&copy);
		return (1);
	}
	else
		destroy_stack(&copy);
	return (0);
}

void		try_pb_clean(t_stack **a, t_stack **b)
{
	destroy_stack(a);
	destroy_stack(b);
}

void		try_pb_insert(int i, t_stack **a, t_stack **b, t_info **info)
{
	while (i--)
	{
		run_command("pb", a, b);
		if (!(push_in_vector(&(*info)->cmd_c, PB, sizeof(char))))
			clean_and_exit(a, b, info, 'm');
	}
}

int			try_pb(t_stack **a, t_stack **b, t_info **info)
{
	t_stack	*copy_a;
	t_stack	*copy_b;
	int		i;

	i = 0;
	copy_a = copy_stack(*a);
	copy_b = copy_stack(*b);
	if (!copy_a)
	{
		try_pb_clean(&copy_a, &copy_b);
		clean_and_exit(a, b, info, 'm');
	}
	while (i < 2)
	{
		run_command("pb", &copy_a, &copy_b);
		if (ft_isslice(copy_a))
		{
			try_pb_insert(i, a, b, info);
			return (1);
		}
		i++;
	}
	try_pb_clean(&copy_a, &copy_b);
	return (0);
}

int fast_changes(t_stack **a, t_stack **b, t_info **info)
{
	if (try_s(a, b, info))
		return (1);
	if (try_pb(a, b, info))
		return (1);
	else
		return (0);
}
