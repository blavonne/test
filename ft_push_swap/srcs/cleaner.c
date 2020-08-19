#include "checker.h"

static void	destroy_stack(t_stack **stack)
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

void		destroy_main(t_main **m)
{
	size_t		i;

	i = 0;
	if ((*m)->cmd_c)
		free((*m)->cmd_c->arr);
	free((*m)->cmd_c);
	if ((*m)->count_steps_i)
		free((*m)->count_steps_i->arr);
	free((*m)->count_steps_i);
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
