#include "checker.h"


static int		try_rb(t_stack *ptr, t_stack *b, t_vector **rb)
{
	ft_printf("====Start try_rb func.====\n");
	while (b && b->value != ptr->value)
	{
		if (!push_in_vector(rb, RB, sizeof(char)))
			return (0);
		b = b->next;
	}
	ft_printf("====End try_rb func.====\n");
	return (1);
}

static int		try_rrb(t_stack *ptr, t_stack *b, t_vector **rrb)
{
	t_stack		*copy;

	ft_printf("====Start try_rrb func.====\n");
	if (!(copy = copy_stack(b)))
		return (0);
	while (copy->value != ptr->value)
	{
		run_command("rrb", 0, &copy);
		if (!push_in_vector(rrb, RRB, sizeof(char)))
		{
			destroy_stack(&copy);
			return (0);
		}
	}
	destroy_stack(&copy);
	ft_printf("====End try_rrb func.====\n");
	return (1);
}

t_vector		*ptr_to_top_b(t_stack *b, t_stack *ptr)
{
	t_vector	*rb;
	t_vector	*rrb;

	ft_printf("====Start ptr_to_top_b func.====\n");
	if (!(rb = create_vector()))
		return (NULL);
	if (!(rrb = create_vector()))
		return (NULL);
	if (!try_rb(ptr, b, &rb) || !try_rrb(ptr, b, &rrb))
	{
		destroy_vector(&rb);
		destroy_vector(&rrb);
		ft_printf("====End ptr_to_top_b func.====\n");
		return (NULL);
	}
	if (rb->next < rrb->next)
	{
		ft_printf("====End ptr_to_top_b func.====\n");
		destroy_vector(&rrb);
		return (rb);
	}
	else
	{
		ft_printf("====End ptr_to_top_b func.====\n");
		destroy_vector(&rb);
		return (rrb);
	}
}
