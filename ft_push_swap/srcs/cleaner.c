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

static void	destroy_vectors(t_vectors **v)
{
	free((*v)->cmd->arr);
	free((*v)->cmd);
	free((*v)->chunk->arr);
	free((*v)->chunk);
	free(*v);
}

void		clean_and_exit(t_stack **a, t_stack **b, t_vectors **v,\
		char option)
{
	(*a) ? destroy_stack(a) : 0;
	(*b) ? destroy_stack(b) : 0;
	(*v) ? destroy_vectors(v) : 0;
	put_errmsg_and_exit(option);
}

void		destroy_map(t_map **map)
{
	free((*map)->size);
	free((*map)->begin);
	free(*map);
}
