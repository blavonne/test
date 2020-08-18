#include "checker.h"

t_vectors		*get_commands(t_stack **a, t_stack **b)
{
	t_vectors		*info;

	if (!(info = create_vectors(VECTOR_SIZE)))
		clean_and_exit(a, b, 0, 'm');
	all_to_b(a, b, &info);
	return (info);
}
