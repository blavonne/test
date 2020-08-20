#include "checker.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	*cmd;
	int		count;

	if (argc == 1)
		put_errmsg_and_exit('d');
	a = read_argv(argc, argv);
	b = NULL;
	while ((count = get_next_line(0, &cmd)))
	{
		if (count < 0)
			break ;
		if (!check_command(cmd))
		{
			ft_printf("This is command: [%s]\n", cmd);
			clean_and_exit(&a, &b, 0, 'c');
		}
		run_command(cmd, &a, &b);
		free(cmd);
	}
	free(cmd);
	check_asc_order(a, b) ? ft_printf("OK\n") : ft_printf("KO\n");
	clean_and_exit(&a, &b, 0, 0);
	return (0);
}
