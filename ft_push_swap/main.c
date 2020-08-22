/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:25:16 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:25:40 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_info(t_info *info)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = info->cmd_c->arr;
	while (i < info->cmd_c->size)
	{
		arr[i] == RB ? ft_printf("%s\n", "rb") : 0;
		arr[i] == RA ? ft_printf("%s\n", "ra") : 0;
		arr[i] == SA ? ft_printf("%s\n", "sa") : 0;
		arr[i] == SB ? ft_printf("%s\n", "sb") : 0;
		arr[i] == SS ? ft_printf("%s\n", "ss") : 0;
		arr[i] == RRA ? ft_printf("%s\n", "rra") : 0;
		arr[i] == RRB ? ft_printf("%s\n", "rrb") : 0;
		arr[i] == PA ? ft_printf("%s\n", "pa") : 0;
		arr[i] == PB ? ft_printf("%s\n", "pb") : 0;
		arr[i] == RR ? ft_printf("%s\n", "rr") : 0;
		arr[i] == RRR ? ft_printf("%s\n", "rrr") : 0;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_info	*info;

	if (argc == 1)
		return (0);
	a = read_argv(argc, argv);
	b = NULL;
	if (check_asc_order(a, b))
	{
		clean_and_exit(&a, &b, 0, 0);
		return (69);
	}
	if (!(info = get_commands(&a, &b)))
		clean_and_exit(&a, &b, &info, 'm');
	print_info(info);
	clean_and_exit(&a, &b, &info, 0);
	return (0);
}
