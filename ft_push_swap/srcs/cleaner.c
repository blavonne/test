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
	free((*v)->arr);
	free(*v);
}

void		destroy_main(t_main **m)
{
	size_t		i;

	i = 0;
	destroy_vector(&(*m)->cmd_c);
	destroy_vector(&(*m)->count_steps_i);
	if ((*m)->cmd_arr)
		while (i < (*m)->arr_size)
			free((*m)->cmd_arr[i++]);
	free((*m)->cmd_arr);
	free(*m);
}

void		clean_and_exit(t_stack **a, t_stack **b, t_main **m,\
		char option)
{
	(*a) ? destroy_stack(a) : 0;
	(*b) ? destroy_stack(b) : 0;
	(*m) ? destroy_main(m) : 0;
	put_errmsg_and_exit(option);
}

void		destroy_map(t_map **map)
{
	free((*map)->size);
	free((*map)->begin);
	free(*map);
}
