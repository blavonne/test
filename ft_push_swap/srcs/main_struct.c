#include "checker.h"

t_main			*create_main_struct()
{
	t_main	*root;

	if (!(root = (t_main *)malloc(sizeof(t_main))))
		return (NULL);
	root->cmd_arr = NULL;
	root->cmd_c = NULL;
	root->count_steps_i = NULL;
	if (!(root->cmd_c = create_vector()))
	{
		destroy_main(&root);
		return (NULL);
	}
	if (!(root->count_steps_i = create_vector()))
	{
		destroy_main(&root);
		return (NULL);
	}
	if (!(root->cmd_arr = create_varr()))
	{
		destroy_main(&root);
		return (NULL);
	}
	root->arr_size = VARR_SIZE;
	return (root);
}