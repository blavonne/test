#include "checker.h"

/*
** ==========PB_FORWARD==========
** This func pushes numbers less than middle_val from top A to top B
*/

static void		pb_forward(t_stack **a, t_stack **b, t_vectors **info,\
		int middle_val)
{
	t_stack		*ptr;

	ptr = (*a);
	while (ptr && ptr->value < middle_val && !(ft_isslice((*a))))
	{
		run_command("pb", a, b);
		if (!push_in_vector(&(*info)->cmd, PB, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		ptr = (*a);
	}
}

/*
** ==========PB_BACK==========
** This func pushes numbers less than middle_val from bottom A to top B
*/

static void		pb_back(t_stack **a, t_stack **b, t_vectors **info,\
		int middle_val)
{
	t_stack		*ptr;

	ptr = (*a);
	while (ptr && ptr->value < middle_val && !(ft_isslice((*a))))
	{
		if (!push_in_vector(&(*info)->cmd, RRA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		run_command("pb", a, b);
		if (!push_in_vector(&(*info)->cmd, PB, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		run_command("rra", a, b);
		ptr = (*a);
	}
}

/*
** ==========SA==========
** This func swaps numbers in A by ascending order if A contains 2 numbers only
*/

static void		sa(t_stack **a, t_stack **b, t_vectors **info)
{
	if ((*a) && (*a)->next && !(*a)->next->next && (*a)->value >\
		(*a)->next->value && !(ft_isslice((*a))))
	{
		run_command("sa", a, b);
		if (!push_in_vector(&(*info)->cmd, SA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

/*
** ==========RA==========
** This func rotates A till a-value is more or equal middle_val
*/

static void		ra(t_stack **a, t_stack **b, t_vectors **info, int middle_val)
{
	t_stack *ptr;

	ptr = (*a);
	while (ptr && check_mid(*a, middle_val) && ptr->value >= middle_val\
	&& !(ft_isslice((*a))))
	{
		run_command("ra", a, b);
		if (!push_in_vector(&(*info)->cmd, RA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		ptr = (*a);
	}
}

/*
** ==========ALL_TO_B==========
** This func keeps the biggest sorted by ascending order numbers in A
** and other numbers puts in B
*/

void			all_to_b(t_stack **a, t_stack **b, t_vectors **info)
{
	int				middle_val;

	print_stacks(*a, *b);
	while ((*a) && (*a)->next && (*a)->next->next && !(ft_isslice((*a))))
	{
		if ((middle_val = get_middle(a)) < 0)
			clean_and_exit(a, b, 0, 'm');
		ft_printf("Middle is = %d\n", middle_val);
		while (check_mid((*a), middle_val) && !(ft_isslice((*a))))
		{
			pb_forward(a, b, info, middle_val);
			ft_printf("This operation is default.\n");
			run_command("rra", a, b);
			pb_back(a, b, info, middle_val);
			ft_printf("This operation is default.\n");
			run_command("ra", a, b);
			ra(a, b, info, middle_val);
		}
		sa(a, b, info);
	}
}
