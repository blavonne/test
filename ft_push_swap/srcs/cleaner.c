#include "checker.h"

void		destroy_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if ((*stack))
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			ptr = tmp->next;
			free(tmp);
			tmp = ptr;
		}
		free(*stack);
	}
}

void		destroy_vector(t_vector **v)
{
	(*v) ? free((*v)->arr) : 0;
	free(*v);
}

void		destroy_main(t_info **m)
{
	size_t		i;

	i = 0;
	if ((*m))
	{
		destroy_vector(&(*m)->cmd_c);
		destroy_vector(&(*m)->count_steps_i);
		if ((*m)->cmd_arr)
			while (i < (*m)->arr_size)
				free((*m)->cmd_arr[i++]);
		free((*m)->cmd_arr);
	}
	free(*m);
}

void		clean_and_exit(t_stack **a, t_stack **b, t_info **m,\
		char option)
{
	(a) && (*a) ? destroy_stack(a) : 0;
	(b) && (*b) ? destroy_stack(b) : 0;
	(m) && (*m) ? destroy_main(m) : 0;
	put_errmsg_and_exit(option);
}

void		destroy_map(t_map **map)
{
	free((*map)->size);
	free((*map)->begin);
	free(*map);
}
