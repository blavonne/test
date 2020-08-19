#include "checker.h"

static int		try_to_push(int count, unsigned char cmd, t_vector **dest)
{
	int		i;

	i = 0;
	while (i++ < count)
		if (!(push_in_vector(dest, cmd, sizeof(char))))
			return (0);
	return (1);
}

int				try_ra(t_stack *a, t_stack *ptr, t_vector **ra)
{
	int		ra_count;
	int		min;
	int		i;

	ft_printf("====Start try_ra func.====\n");
	i = 1;
	if (ptr && a)
	{
		min = ft_abs(ptr->value - a->value);
		ra_count = (ptr->value < a->value) ? 0 : 1;
		a = (a->next) ? a->next : 0;
	}
	while (a && ptr)
	{
		if (ft_abs(ptr->value - a->value) < min)
		{
			ra_count = (ptr->value < a->value) ? i : i + 1;
			min = ft_abs(ptr->value - a->value);
		}
		i++;
		a = a->next;
	}
	ft_printf("====End try_rra func.====\n");
	return (try_to_push(ra_count, RA, ra));
}

int				try_rra(t_stack *a, t_stack *ptr, t_vector **rra)
{
	int		rra_count;
	int		min;
	int		i;
	t_stack	*begin;

	ft_printf("====Start try_rra func.====\n");
	i = 1;
	rra_count = 0;
	if (a && ptr)
	{
		min = ft_abs(ptr->value - a->value);
		begin = a;
	}
	while (a && ptr)
	{
		if (ft_abs(ptr->value - a->value) < min)
		{
			rra_count = (ptr->value < a->value) ? i - 1 : i;
			min = ft_abs(ptr->value - a->value);
		}
		i++;
		run_command("rra", &a, 0);
		if (a == begin)
			break ;
	}
	ft_printf("====End try_rra func.====\n");
	return (try_to_push(rra_count, RRA, rra));
}

int				add_new_way(t_vector **way, t_vector **ra, t_vector **rra)
{
	if ((*ra)->next < (*rra)->next)
	{
		destroy_vector(rra);
		if (!(cat_vectors(way, *ra)))
		{
			destroy_vector(ra);
			return (0);
		}
	}
	else
	{
		destroy_vector(ra);
		if (!(cat_vectors(way, *rra)))
		{
			destroy_vector(rra);
			return (0);
		}
	}
	return (1);
}

int				ptr_to_a(t_stack *a, t_stack *ptr, t_vector **way)
{
	t_vector	*ra;
	t_vector	*rra;

	if (!(ra = create_vector()))
		return (0);
	if (!(rra = create_vector()))
		return (0);
	if (!try_ra(a, ptr, &ra) || !try_rra(a, ptr, &rra))
	{
		destroy_vector(&ra);
		destroy_vector(&rra);
		return (0);
	}
	if (!add_new_way(way, &ra, &rra))
		return (0);
	return (1);
}