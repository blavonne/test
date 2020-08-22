/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 03:03:24 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 03:03:26 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_map	*set_map(t_map *map, int i)
{
	map->begin[i] = map->beg;
	map->size[i] = map->end - map->beg + 1;
	map->beg = map->end + 1;
	map->end = map->beg + 1;
	return (map);
}

void	destroy_map(t_map **map)
{
	free((*map)->size);
	free((*map)->begin);
	free(*map);
}
