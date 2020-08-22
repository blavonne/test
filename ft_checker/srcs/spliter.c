/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:40:48 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:40:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_split(char ***matrix)
{
	int		i;

	i = 0;
	while ((**matrix) && (*matrix) && (*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	if ((*matrix))
		free((*matrix));
}

static char	set_delimiter(char *str)
{
	int		i;
	char	delimiter;

	i = 0;
	if (!str)
		return (0);
	if (!ft_issign(str[0]) && !ft_isdigit(str[0]))
		return (0);
	else
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	delimiter = str[i];
	return (delimiter);
}

int			try_to_split(char *str, t_stack **stack)
{
	char	delimiter;
	int		i;
	char	**res;

	res = NULL;
	if (!(delimiter = set_delimiter(str)))
		clean_and_exit(stack, 0, 0, 'd');
	if (!(res = ft_strsplit(str, delimiter)))
		clean_and_exit(stack, 0, 0, 'm');
	i = 0;
	while (res && res[i])
	{
		if (!ft_isnumber(res[i]))
		{
			clean_split(&res);
			clean_and_exit(stack, 0, 0, 'd');
		}
		else
			push_in_stack(stack, get_number(res[i], stack));
		i++;
	}
	clean_split(&res);
	return (1);
}
