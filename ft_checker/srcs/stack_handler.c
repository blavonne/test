#include "checker.h"

t_stack		*copy_stack(t_stack *src)
{
	t_stack		*copy;
	t_stack		*copy_head;

	copy_head = NULL;
	if (src)
	{
		if (!(copy = create_stack()))
			return (NULL);
		copy_head = copy;
		while (src)
		{
			copy->value = src->value;
			if (src->next && !(copy->next = create_stack()))
			{
				destroy_stack(&copy_head);
				return (NULL);
			}
			copy = copy->next;
			src = src->next;
		}
	}
	return (copy_head);
}

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
}

t_stack		*create_stack(void)
{
	t_stack		*elem;

	if (!(elem = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	elem->value = 0;
	elem->next = NULL;
	return (elem);
}
