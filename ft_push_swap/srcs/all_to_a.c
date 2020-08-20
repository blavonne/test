#include "checker.h"

void			print_vector(t_vector *way)
{
	int		i;
	unsigned char	*arr;

	i = 0;
	arr = way->arr;
	ft_printf("====Vector command line is: ");
	while (i < way->next)
	{
		arr[i] == RA ? ft_printf("ra ") : 0;
		arr[i] == RB ? ft_printf("rb ") : 0;
		arr[i] == RR ? ft_printf("rr ") : 0;
		arr[i] == SA ? ft_printf("sa ") : 0;
		arr[i] == SB ? ft_printf("sb ") : 0;
		arr[i] == PA ? ft_printf("pa ") : 0;
		arr[i] == PB ? ft_printf("pb ") : 0;
		arr[i] == RRA ? ft_printf("rra ") : 0;
		arr[i] == RRB ? ft_printf("rrb ") : 0;
		arr[i] == RRR ? ft_printf("rrr ") : 0;
		i++;
	}
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
	ft_printf("Current value: %d.\n", ptr->value);
	print_vector(way);
	optimize_way(way);
	print_vector(way);
	//4.закинуть в varr
	push_in_varr(m, way);
	push_in_vector(&(*m)->count_steps_i, way->next, sizeof(int));
	return (1);
}

int				find_min_index(t_vector *count_steps_i)
{
	int		*arr;
	int		i;
	int		min;

	arr = count_steps_i->arr;
	min = -1;
	if (arr)
		min = 0;
	i = 0;
	while (arr && i < count_steps_i->next)
	{
		if (arr[i] < arr[min])
			min = i;
		i++;
	}
	return (min);
}

//int				merge_commands(t_stack **a, t_stack **b, t_main **m, int count)
//{
//	int				i;
//	unsigned char	*arr;
//
//	i = 0;
//	if ((*m)->cmd_arr[count])
//	arr = (*m)->cmd_arr[count]->arr;
//	while (i < (*m)->cmd_arr[count]->next)
//	{
//		push_in_vector(&(*m)->cmd_c, )
//	}
//}

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
	count = find_min_index((*m)->count_steps_i);
	if (count < 0)
		clean_and_exit(a, b, m, 'm');
	ft_printf("Min is: %d\n", count);
//	merge_commands(a, b, m, count);
//	if (b == NULL)
//		return ;
//	all_to_a(a, b, m);
}
