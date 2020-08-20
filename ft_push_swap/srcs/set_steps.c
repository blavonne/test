#include "checker.h"

int				set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_main **m)
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
	push_in_varr(m, way);
	push_in_vector(&(*m)->count_steps_i, way->next, sizeof(int));
//	ft_printf("====End set steps func.====\n");
	return (1);
}
