#include "checker.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int		n;
	int		i;

	n = 5;
	ft_printf("%s\n", "Stack status:");
	while (a || b)
	{
		i = 0;
		if (a)
		{
			ft_printf("%-*d", n, a->value);
			a = a->next;
		}
		else
			while (i++ < n)
				ft_printf(" ");
		if (b)
		{
			ft_printf("%-*d", n, b->value);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("%-*c%-*c\n%-*c%-*c\n\n", n, '-', n, '-', n, 'a', n, 'b');
}

int		check_command(char *cmd)
{
	if (ft_strequ("sa", cmd) || ft_strequ("sb", cmd) || ft_strequ("ss", cmd) ||\
	ft_strequ("pa", cmd) || ft_strequ("pb", cmd) || ft_strequ("ra", cmd) ||\
	ft_strequ("rb", cmd) || ft_strequ("rr", cmd) || ft_strequ("rra", cmd) ||\
	ft_strequ("rrb", cmd) || ft_strequ("rrr", cmd))
		return (1);
	return (0);
}

int		check_order(t_stack *a, t_stack *b)
{
	t_stack	*ptr;

	if (b)
		return (0);
	else if (a)
	{
		ptr = a;
		while (ptr->next)
		{
			a = ptr->next;
			while (a)
			{
				if (a->value <= ptr->value)
					return (0);
				a = a->next;
			}
			ptr = ptr->next;
		}
	}
	return (1);
}

int		check(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	*cmd;
	int		count;

	if (argc == 1)
		put_errmsg_and_exit('d');
	a = read_argv(argc, argv);
	b = NULL;
	print_stacks(a, b);
	while ((count = get_next_line(0, &cmd)))
	{
		if (count < 0 || !check_command(cmd))
			break ;
		run_command(cmd, &a, &b);
		free(cmd);
	}
	free(cmd);
	check_order(a, b) ? ft_printf("OK\n") : ft_printf("KO\n");
	clean_and_exit(&a, &b, 0, 0);
	return (0);
}

//int		main(int argc, char **argv)
//{
//	t_stack	*a;
//	t_stack *b;
//	char	*cmd;
//	int		count;
//
//	if (argc == 1)
//		put_errmsg_and_exit('d');
//	a = read_argv(argc, argv);
//	b = NULL;
//	print_stacks(a, b);
//	while ((count = get_next_line(0, &cmd)))
//	{
//		if (count < 0 || !check_command(cmd))
//			break ;
//		run_command(cmd, &a, &b);
//		free(cmd);
//	}
//	free(cmd);
//	check_order(a, b) ? ft_printf("OK\n") : ft_printf("KO\n");
//	clean_and_exit(&a, &b, 0, 0);
//	return (0);
//}
