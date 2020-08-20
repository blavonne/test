#include "checker.h"

static int			resize_varr(t_main **v)
{
	t_vector	**narr;

	if (!(narr = (t_vector **)malloc(sizeof(t_vector *) * ((*v)->arr_size +\
	VARR_SIZE))))
		return (0);
	narr = ft_memset(narr, 0, sizeof(t_vector *) * ((*v)->arr_size +\
	VARR_SIZE));
	narr = ft_memcpy(narr, (*v)->cmd_arr, sizeof(t_vector *) * (*v)->arr_size);
	(*v)->arr_size += VARR_SIZE;
	free((*v)->cmd_arr);
	(*v)->cmd_arr = narr;
	return (1);
}

int					push_in_varr(t_main **m, t_vector *tmp)
{
	if ((*m)->arr_next + 1 > (*m)->arr_size)
		if (!resize_varr(m))
			return (0);
	(*m)->cmd_arr[(*m)->arr_next] = tmp;
	(*m)->arr_next++;
	return (1);
}

t_vector			**create_varr(void)
{
	t_vector	**v_arr;
	int			i;

	i = 0;
	if (!(v_arr = (t_vector **)malloc(sizeof(t_vector *) * VARR_SIZE)))
		return (NULL);
	while (i < VARR_SIZE)
	{
		v_arr[i] = NULL;
		i++;
	}
	return (v_arr);
}
