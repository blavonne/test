#include "checker.h"

int					set_number(t_bigint *big, t_stack **stack)
{
	int		i;
	int		res;

	i = 1;
	res = 0;
	big->length = set_len_big(big);
	if (big->length == BIGINT_SIZE && big->bigint[big->length - 1] > 2)
		clean_exit(stack, 'd');
	while (i <= big->length)
	{
		if ((res == INT_MAX / 10 && ((big->sign != -1 && big->bigint[0] >\
		INT_MAX % 10) || (big->sign == -1 && big->bigint[0] > INT_MIN % 10)))\
		|| (res > INT_MAX / 10))
			clean_exit(stack, 'd');
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
		clean_exit(stack, 'd');
	if (ft_issign(str[0]))
		big.sign = (str[0] == '-') ? -1 : 1;
	while (i >= 0 && ((ft_issign(str[0]) && j < BIGINT_SIZE + 1) ||\
	(!ft_issign(str[0]) && j < BIGINT_SIZE)))
	{
		if (ft_isdigit(str[i]))
			big.bigint[j++] = str[i] - 48;
		else if (!ft_isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] ==\
		'+')))
			clean_exit(stack, 'd');
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
					clean_exit(stack, 'd');
				cur = cur->next;
			}
		}
		head = head->next;
	}
}

void				clean_exit(t_stack **stack, char type)
{
	destroy_stack(stack);
	put_errmsg_and_exit(type);
}

t_stack				*read_argv(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;

	i = 1;
	stack = NULL;
	while (i++ < argc)
	{
		if (!(tmp = create_elem()))
			clean_exit(&stack, 'm');
		push_in_stack(&stack, tmp);
	}
	i = 1;
	tmp = stack;
	while (i < argc)
	{
		tmp->value = get_number(argv[i], &stack);
		tmp = tmp->next;
		i++;
	}
	check_duplicates(&stack);
	return (stack);
}
