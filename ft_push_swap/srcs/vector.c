#include "checker.h"

static int		resize(t_vector **v)
{
	void			*tmp;

	if (!(tmp = malloc((*v)->size + VECTOR_SIZE)))
		return (0);
	ft_memset(tmp, 0, (*v)->size + VECTOR_SIZE);
	tmp = ft_memcpy(tmp, (*v)->arr, (*v)->size);
	(*v)->size += VECTOR_SIZE;
	free((*v)->arr);
	(*v)->arr = tmp;
	return (1);
}

void			print_vector(t_vector **v)
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

int				push_in_vector(t_vector **v, int value, size_t size)
{
	unsigned char	*cmd;
	int				*arr;
	int				i;

	i = (*v)->cur;
	if (size * (*v)->cur + size >= (*v)->size)
		if (!resize(v))
			return (0);
	if (size == sizeof(char))
	{
		cmd = (*v)->arr;
		cmd[i] = (unsigned char)value;
		(*v)->cur++;
	}
	else if (size == sizeof(int))
	{
		arr = (*v)->arr;
		arr[i] = value;
		(*v)->cur++;
	}
	return (1);
}

static t_vector		*create_vector(size_t size)
{
	t_vector	*tmp;

	if (!(tmp = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	if (!(tmp->arr = malloc(size)))
	{
		free(tmp);
		return (NULL);
	}
	ft_memset(tmp->arr, 0, size);
	tmp->cur = 0;
	tmp->size = size;
	return (tmp);
}

t_vectors		*create_vectors(size_t size)
{
	t_vectors	*root;

	if (!(root = (t_vectors *)malloc(sizeof(t_vectors))))
		return (NULL);
	if (!(root->cmd = create_vector(size)))
	{
		free(root);
		return (NULL);
	}
	if (!(root->chunk = create_vector(size)))
	{
		free(root->chunk);
		free(root);
		return (NULL);
	}
	return (root);
}
