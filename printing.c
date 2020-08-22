void				print_arr(int *arr, int size);//del
void				print_vector(t_vector *way);//del
void				print_int_vector(t_vector *v);//del

void			print_arr(int *arr, int size)//del
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_printf("[%i]%-3d ", i, arr[i]);
		i++;
	}
	ft_printf("\n");
}

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
		arr[i] == SS ? ft_printf("ss ") : 0;
		arr[i] == PA ? ft_printf("pa ") : 0;
		arr[i] == PB ? ft_printf("pb ") : 0;
		arr[i] == RRA ? ft_printf("rra ") : 0;
		arr[i] == RRB ? ft_printf("rrb ") : 0;
		arr[i] == RRR ? ft_printf("rrr ") : 0;
		i++;
	}
	ft_printf("\n");
}

void			print_int_vector(t_vector *v)
{
	size_t		i;
	int			*arr;

	i = 0;
	if (v)
	{
		arr = v->arr;
		while (i < v->next)
		{
			ft_printf("%d ", arr[i]);
			i++;
		}
		ft_printf("\n");
	}
}

void				print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}
