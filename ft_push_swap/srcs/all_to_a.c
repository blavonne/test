#include "checker.h"

void			print_vector(t_vector *way)//del
{
	size_t			i;
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

static int		find_min_index(t_vector *count_steps_i)
{
	int		*arr;
	size_t	i;
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

static int		merge_commands(t_stack **a, t_stack **b, t_info **m,\
		int count)
{
	size_t			i;
	unsigned char	*arr;

//	ft_printf("====Start merge_commands func.====\n");
	i = 0;
	if (!(*m)->arr_size || (*m)->cmd_arr == NULL ||\
	(*m)->cmd_arr[count] == NULL)
		return (0);
	arr = (*m)->cmd_arr[count]->arr;
	while (i < (*m)->cmd_arr[count]->next)
	{
		if (!(push_in_vector(&(*m)->cmd_c, arr[i], sizeof(char))))
			return (0);
		arr[i] == RA ? run_command("ra", a, b) : 0;
		arr[i] == RB ? run_command("rb", a, b) : 0;
		arr[i] == RR ? run_command("rr", a, b) : 0;
		arr[i] == SA ? run_command("sa", a, b) : 0;
		arr[i] == SB ? run_command("sb", a, b) : 0;
		arr[i] == PA ? run_command("pa", a, b) : 0;
		arr[i] == PB ? run_command("pb", a, b) : 0;
		arr[i] == RRA ? run_command("rra", a, b) : 0;
		arr[i] == RRB ? run_command("rrb", a, b) : 0;
		arr[i] == RRR ? run_command("rrr", a, b) : 0;
		i++;
	}
//	ft_printf("====End merge_commands func.====\n");
	return (1);
}

void			reset_cmd_arr(t_info **m)
{
	size_t		i;

	i = 0;
	while (i < (*m)->arr_next)
	{
		ft_memset((*m)->cmd_arr[i]->arr, 0, (*m)->cmd_arr[i]->next);
		i++;
	}
	(*m)->arr_next = 0;
	ft_memset((*m)->count_steps_i->arr, 0, sizeof(int) *\
	(*m)->count_steps_i->next);
	(*m)->count_steps_i->next = 0;
}

//int		gl = 0;//del

void			all_to_a(t_stack **a, t_stack **b, t_info **m)
{
	t_stack	*ptr;
	int		shortest_way_index;

//	ft_printf("%i iteration start.\n", gl);
//	gl++;
	ptr = (*b);
	while (ptr)
	{
//		ft_printf("Initial statement:\n");
//		print_stacks(*a, *b);
//		ft_printf("Current value: %d.\n", ptr->value);
		if (!set_steps((*a), (*b), ptr, m))
			clean_and_exit(a, b, m, 'm');
		ptr = ptr->next;
	}
	shortest_way_index = find_min_index((*m)->count_steps_i);
	if (shortest_way_index < 0)
		clean_and_exit(a, b, m, 'm');
//	ft_printf("%i iteration middle.\n", gl);
//	ft_printf("Min is: %d.\nStart insertion.\n", shortest_way_index);
	if (!merge_commands(a, b, m, shortest_way_index))
		clean_and_exit(a, b, m, 'm');
	reset_cmd_arr(m);
	if ((*b) == NULL)
		return ;
	else
		all_to_a(a, b, m);
}
