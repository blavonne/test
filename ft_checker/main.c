/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:42:07 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:42:10 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	*cmd;
	int		count;

	if (argc == 1)
		return (0);
	a = read_argv(argc, argv);
	b = NULL;
	while ((count = get_next_line(0, &cmd)))
	{
		if (count < 0)
			break ;
		if (!check_command(cmd))
			clean_and_exit(&a, &b, 0, 'c');
		run_command(cmd, &a, &b);
		free(cmd);
	}
	free(cmd);
	check_asc_order(a, b) ? ft_printf("OK\n") : ft_printf("KO\n");
	clean_and_exit(&a, &b, 0, 0);
	return (0);
}
