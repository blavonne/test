#include "checker.h"

void			print_vector(t_vector *way)
{
	int		i;
	unsigned char	*arr;

	i = 0;
	arr = way->arr;
	ft_printf("====Vector command line is: ");
	while (i < way->next)
		ft_printf("%d ", arr[i++]);
	ft_printf("\n");
}

int				set_steps(t_stack *a, t_stack *b, t_stack *ptr, t_main **m)
{
	t_vector	*way;

	//1.вытолкнуть ptr наверх Б
	if (!(way = ptr_to_top_b(b, ptr)))
		return (0);
	//2.найти место для ptr в А
	if (!ptr_to_a(a, ptr, &way))
		return (0);
	//3.переместить в А
	if (!push_in_vector(&way, PA, sizeof(char)))
		return (0);
	print_vector(way);
//	optimize_way(way);
	return (1);
}

void			all_to_a(t_stack **a, t_stack **b, t_main **m)
{
	t_stack	*ptr;
	int		count;

	count = 0;
	ptr = (*b);
	ft_printf("Initial statement:\n");
	print_stacks(*a, *b);
	while (ptr)
	{
		if (!set_steps((*a), (*b), ptr, m))
			clean_and_exit(a, b, m, 'm');
		ft_printf("Stacks statement after set_steps:\n");
		print_stacks(*a, *b);
		ptr = ptr->next;
	}
//	count = find_min_index((*m)->count_steps_i);
//	merge_commands(a, b, m, count);
//	if (b == NULL)
//		return ;
//	all_to_a(a, b, m);
}
