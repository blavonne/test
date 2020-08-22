/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:26:08 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:26:27 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info			*create_main_struct(void)
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
