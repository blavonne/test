/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					set_number(t_bigint *big, t_stack **stack)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	big->length = set_len_big(big);
	if (big->length == BIGINT_SIZE && big->bigint[big->length - 1] > 2)
		clean_and_exit(stack, 0, 0, 'd');
	while (i <= big->length)
	{
		if ((res == INT_MAX / 10 && ((big->sign != -1 && big->bigint[0] >\
		INT_MAX % 10) || (big->sign == -1 && big->bigint[0] > INT_MIN % 10)))\
		|| (res > INT_MAX / 10))
			clean_and_exit(stack, 0, 0, 'd');
		res *= 10;
		res += big->bigint[big->length - i];
		i++;
	}
	if (big->sign == -1)
		res = -res;
	return (res);
}

int					get_number(char *str, t_stack **stack)
{
	t_bigint	big;
	int			number;
	int			i;
	int			j;

	j = 0;
	i = (int)ft_strlen(str) - 1;
	initialize_big(&big);
	if (i > BIGINT_SIZE)
		clean_and_exit(stack, 0, 0, 'd');
	if (ft_issign(str[0]))
		big.sign = (str[0] == '-') ? -1 : 1;
	while (i >= 0 && ((ft_issign(str[0]) && j < BIGINT_SIZE + 1) ||\
	(!ft_issign(str[0]) && j < BIGINT_SIZE)))
	{
		if (ft_isdigit(str[i]))
			big.bigint[j++] = str[i] - 48;
		else if (!ft_isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] ==\
		'+')))
			clean_and_exit(stack, 0, 0, 'd');
		i--;
	}
	number = set_number(&big, stack);
	return (number);
}

void				check_duplicates(t_stack **stack)
{
	t_stack		*cur;
	t_stack		*head;

	head = (*stack);
	while (head->next)
	{
		cur = head->next;
		{
			while (cur)
			{
				if (cur->value == head->value)
					clean_and_exit(stack, 0, 0, 'd');
				cur = cur->next;
			}
		}
		head = head->next;
	}
}

t_stack				*read_argv(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]))
			push_in_stack(&stack, get_number(argv[i], &stack));
		else
			try_to_split(argv[i], &stack);
		i++;
	}
	check_duplicates(&stack);
	return (stack);
}
