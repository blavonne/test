#include "checker.h"

t_main		*get_commands(t_stack **a, t_stack **b)
{
	t_main		*info;

	if (!(info = create_main_struct()))
		clean_and_exit(a, b, 0, 'm');
	all_to_b(a, b, &info);
	all_to_a(a, b, &info);
	return (info);
}
