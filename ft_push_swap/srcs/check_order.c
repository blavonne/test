#include "checker.h"

int		check_asc_order(t_stack *a, t_stack *b)
{
	if (b || a == NULL)
		return (0);
	else if (a)
	{
		while (a->next)
		{
			if (a->value >= a->next->value)
				return (0);
			a = a->next;
		}
	}
	return (1);
}

int		check_dsc_order(t_stack *a)
{
	if (a == NULL)
		return (0);
	else if (a)
	{
		while (a->next)
		{
			if (a->value <= a->next->value)
				return (0);
			a = a->next;
		}
	}
	return (1);
}
