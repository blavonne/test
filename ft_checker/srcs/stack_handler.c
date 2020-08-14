#include "checker.h"

void		push_in_stack(t_stack **stack, t_stack *next)
{
	t_stack	*ptr;

	if (!(*stack))
	{
		(*stack) = next;
		return ;
	}
	ptr = (*stack);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = next;
	next->prev = ptr;
}

t_stack		*create_elem(void)
{
	t_stack		*elem;

	if (!(elem = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	elem->value = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

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
