#include "checker.h"

static int			resize(t_vector **v)
{
	void			*tmp;

	if (!(tmp = malloc((*v)->size + V_SIZE)))
		return (0);
	ft_memset(tmp, 0, (*v)->size + V_SIZE);
	tmp = ft_memcpy(tmp, (*v)->arr, (*v)->size);
	(*v)->size += V_SIZE;
	free((*v)->arr);
	(*v)->arr = tmp;
	return (1);
}

void				print_vector(t_vector **v)
{
	int		i;
	unsigned char	*arr;

	i = 0;
	arr = (*v)->arr;
	while (i < (*v)->size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("\n");
}

int					push_in_vector(t_vector **v, int value, size_t size)
{
	unsigned char	*cmd;
	int				*arr;
	size_t			i;

	i = (*v)->next;
	if (size * (*v)->next + size >= (*v)->size)
		if (!resize(v))
			return (0);
	if (size == sizeof(char))
	{
		cmd = (*v)->arr;
		cmd[i] = (unsigned char)value;
		(*v)->next++;
	}
	else if (size == sizeof(int))
	{
		arr = (*v)->arr;
		arr[i] = value;
		(*v)->next++;
	}
	return (1);
}

t_vector			*create_vector()
{
	t_vector	*tmp;

	if (!(tmp = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(tmp->arr = malloc(V_SIZE)))
	{
		free(tmp);
		return (NULL);
	}
	ft_memset(tmp->arr, 0, V_SIZE);
	tmp->next = 0;
	tmp->size = V_SIZE;
	return (tmp);
}
