#include "checker.h"


static int		try_rb(t_stack *ptr, t_stack *b, t_vector **rb)
{
	while (b && b->value != ptr->value)
	{
		if (!push_in_vector(rb, RB, sizeof(char)))
			return (0);
		b = b->next;
	}
	return (1);
}

static t_stack	*copy_stack(t_stack *src)
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

static int		try_rrb(t_stack *ptr, t_stack *b, t_vector **rrb)
{
	t_stack		*b_cpy;

	if (!(b_cpy = copy_stack(b)))
		return (0);
	while (b_cpy->value != ptr->value)
	{
		run_command("rrb", 0, &b_cpy);
		if (!push_in_vector(rrb, RRB, sizeof(char)))
		{
			destroy_stack(&b_cpy);
			return (0);
		}
	}
	destroy_stack(&b_cpy);
	return (1);
}

t_vector		*ptr_to_top_b(t_stack *b, t_stack *ptr)
{
	t_vector	*rb;
	t_vector	*rrb;

	if (!(rb = create_vector()))
		return (NULL);
	if (!(rrb = create_vector()))
		return (NULL);
	try_rb(ptr, b, &rb);
	print_stacks(0, b);
	try_rrb(ptr, b, &rrb);
	print_stacks(0, b);
	if (!try_rb(ptr, b, &rb) || !try_rrb(ptr, b, &rrb))
	{
		destroy_vector(&rb);
		destroy_vector(&rrb);
		return (NULL);
	}
	if (rb->next < rrb->next)
	{
		destroy_vector(&rrb);
		return (rb);
	}
	else
	{
		destroy_vector(&rb);
		return (rrb);
	}
}
