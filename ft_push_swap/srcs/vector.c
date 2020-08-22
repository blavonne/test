/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:32:49 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:34:04 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int					push_in_vector(t_vector **v, int value, size_t size)
{
	unsigned char	*cmd;
	int				*arr;
	size_t			i;

	i = (*v)->next;
	while (size * (*v)->next + size > (*v)->size)
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

t_vector			*copy_vector(t_vector *src)
{
	t_vector	*copy;

	if (src)
	{
		if (!(copy = (t_vector *)malloc(sizeof(t_vector))))
			return (NULL);
		copy->size = src->size;
		copy->next = src->next;
		if (!(copy->arr = malloc(src->size)))
		{
			free(copy);
			return (NULL);
		}
		copy->arr = ft_memcpy(copy->arr, src->arr, src->size);
		return (copy);
	}
	return (NULL);
}

int					cat_vectors(t_vector **dest, t_vector *src)
{
	size_t			i;
	unsigned char	*src_arr;

	if (src && (*dest))
	{
		i = 0;
		src_arr = src->arr;
		while (i < src->next)
		{
			if (!(push_in_vector(dest, src_arr[i], sizeof(char))))
				return (0);
			i++;
		}
	}
	return (1);
}

t_vector			*create_vector(void)
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
