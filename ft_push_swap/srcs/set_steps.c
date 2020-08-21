#include "checker.h"

int				set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_info **m)
{
	t_vector	*way;

//	ft_printf("====Start set steps func.====\n");
	//1.вытолкнуть ptr наверх Б
	if (!(way = ptr_to_top_b(b, ptr)))
		return (0);
	//2.найти место для ptr в А
	if (!ptr_to_a(a, ptr, &way))
		return (0);
	//3.переместить в А
	if (!push_in_vector(&way, PA, sizeof(char)))
		return (0);
//	print_vector(way);
	optimize_way(way);
//	print_vector(way);
	//4.закинуть в varr
	if (!push_in_varr(m, way))
	{
		destroy_vector(&way);
		return (0);
	}
	if (!(push_in_vector(&(*m)->count_steps_i, way->next, sizeof(int))))
	{
		destroy_vector(&way);
		return(0);
	}
//	ft_printf("====End set steps func.====\n");
//	ft_printf("set_steps func\n");
//	print_vector((*m)->cmd_c);
	return (1);
}
