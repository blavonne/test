#include "checker.h"

void	print_info(t_main *info)
{
	int				i;
	unsigned char	*arr;

	i = 0;
	arr = info->cmd_c->arr;
//	ft_printf("Command line:\n");
	while (i < info->cmd_c->size)
	{
		arr[i] == RB ? ft_printf("%s ", "rb") : 0;
		arr[i] == RA ? ft_printf("%s ", "ra") : 0;
		arr[i] == SA ? ft_printf("%s ", "sa") : 0;
		arr[i] == SB ? ft_printf("%s ", "sb") : 0;
		arr[i] == RRA ? ft_printf("%s ", "rra") : 0;
		arr[i] == RRB ? ft_printf("%s ", "rrb") : 0;
		arr[i] == PA ? ft_printf("%s ", "pa") : 0;
		arr[i] == PB ? ft_printf("%s ", "pb") : 0;
		arr[i] == '\n' ? ft_printf("\n") : 0;
		i++;
	}
}

int		reset_info(t_main **info)
{
	t_vector		*gnl;
	int				i;
	unsigned char	*cmd_line;

	i = 0;
	if (!(*info) || !(*info)->cmd_c || !(*info)->cmd_c->arr)
		return (0);
	if (!(gnl = create_vector()))
		return (0);
	cmd_line = (*info)->cmd_c->arr;
	while (i < (*info)->cmd_c->next)
	{
		push_in_vector(&gnl, cmd_line[i], sizeof(char));
		push_in_vector(&gnl, '\n', sizeof(char));
		i++;
	}
	destroy_vector(&(*info)->cmd_c);
	(*info)->cmd_c = gnl;
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_main *info;

	if (argc == 1)
		put_errmsg_and_exit('d');
	a = read_argv(argc, argv);
	b = NULL;
	if (check_asc_order(a, b))
	{
		clean_and_exit(&a, &b, 0, 0);
		return (69);
	}
	info = get_commands(&a, &b);
//	ft_printf("Main status: ");
//	print_stacks(a, b);
//	print_info(info);
	if (reset_info(&info))
		print_info(info);
	clean_and_exit(&a, &b, &info, 0);
	return (0);
}