#include "checker.h"


void			ptr_to_top_b(t_stack **b, t_stack *ptr, t_main **v)
{
	int		r_count;
	int		rr_count;
	int		i;

	i = 0;
	r_count = try_r((*b), ptr);
	rr_count = try_rr((*b), ptr);
	if (r_count < rr_count)
	{
		push_in_vector(&(*v)->count_steps_i, r_count, sizeof(int));
		
	}
}

int				set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_main **v)
{
	t_vector	*way;

	//1.вытолкнуть ptr наверх, записать это в cmd_arr
	ptr_to_top_b(&b, ptr, v);
}

void			all_to_a(t_stack **a, t_stack **b, t_main **info)
{
	t_stack	*ptr;
	int		count;

	count = 0;
	ptr = (*b);
	while (ptr)
	{
		if (!set_steps((*a), (*b), ptr, info))
			clean_and_exit(a, b, info, 'm');
		ptr = ptr->next;
	}
	count = find_min_index((*info)->count_steps_i);
	merge_commands(a, b, info, count);
	if (b == NULL)
		return ;
	all_to_a(a, b, info);
}
