#include "checker.h"

t_info			*create_main_struct()
{
	t_info	*root;

	if (!(root = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	root->cmd_arr = NULL;
	root->cmd_c = NULL;
	root->count_steps_i = NULL;
	root->cmd_c = create_vector();
	root->count_steps_i = create_vector();
	if (!root->cmd_c || !root->count_steps_i)
	{
		destroy_main(&root);
		return (NULL);
	}
	root->arr_size = VARR_SIZE;
	root->arr_next = 0;
	return (root);
}
