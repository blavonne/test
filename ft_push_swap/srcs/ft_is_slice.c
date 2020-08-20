#include "checker.h"

int		check_point(t_stack *a, t_stack *point, char order)
{
	t_stack	*ptr;
	int		i;

	ptr = point;
	if (order == 'a')
		i = (check_asc_order(point, 0)) ? 1 : 0;
//	else if (order == 'd')//descending order
//		i = (check_dsc_order(point)) ? 2 : 0;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if (i == 1 && ptr && ptr->value < a->value || i == 2 && ptr->value >\
	a->value)
		return (1);
	return (0);
}

int		ft_isslice(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr->next)
	{
		while (ptr && ptr->next && ptr->value < ptr->next->value)
			ptr = ptr->next;
		if (!ptr || check_point(a, ptr->next, 'a'))
			return (1);
		else
			break ;
	}
//====descending order====
//	ptr = a;
//	while (ptr->next)
//	{
//		while (ptr && ptr->value < ptr->next->value)
//			ptr = ptr->next;
//		if (!ptr || check_point(a, ptr->next, 'd'))
//			return (1);
//		else
//			break ;
//	}
	return (0);
}
