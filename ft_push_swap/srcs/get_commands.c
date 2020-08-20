#include "checker.h"


int			rotate(t_stack **a, t_main **m, char *cmd)
{
	t_stack			*copy;
	t_vector		*tmp;
	int				i;
	unsigned char	c;

	c = (ft_strequ(cmd, "ra")) ? RA : RRA;
	i = 0;
	if (!(copy = copy_stack((*a))))
		return (0);
	if (!(tmp = create_vector()))
	{
		destroy_stack(&copy);
		return (0);
	}
	while (!check_asc_order(copy, 0))
	{
		run_command(cmd, &copy, 0);
		push_in_vector(&tmp, c, sizeof(char));
		i++;
	}
	push_in_varr(m, tmp);
	destroy_stack(&copy);
	return (i);
}

int			sort_slice(t_stack **a, t_main **m)
{
	int		ra;
	int		rra;
	int		i;

	i = 0;
	if (check_asc_order((*a), 0))
		return (1);
	ra = rotate(a, m, "ra");
	rra = rotate(a, m, "rra");
	if (ra < rra)
	{
		cat_vectors(&(*m)->cmd_c, (*m)->cmd_arr[0]);
		while (i++ < (*m)->cmd_arr[0]->next)
			run_command("ra", a, 0);
	}
	else
	{
		while (i++ < (*m)->cmd_arr[0]->next)
			run_command("rra", a, 0);
		cat_vectors(&(*m)->cmd_c, (*m)->cmd_arr[1]);
	}
	return (1);
}

t_main		*get_commands(t_stack **a, t_stack **b)
{
	t_main		*main;

	if (!(main = create_main_struct()))
		clean_and_exit(a, b, 0, 'm');
	all_to_b(a, b, &main);
	all_to_a(a, b, &main);
	if (ft_isslice(*a))
		ft_printf("Is slice.\n");
	else
		ft_printf("Is NOT slice.\n");
//	if (!sort_slice(a, &main))
//		clean_and_exit(a, b, &main, 'm');
	return (main);
}
