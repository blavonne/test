#include "checker.h"

t_bigint			initialize_big(t_bigint *elephant)
{
	int		i;

	i = 0;
	while (i < BIGINT_SIZE)
	{
		elephant->bigint[i] = 0;
		i++;
	}
	elephant->sign = 0;
	return (*elephant);
}

int					set_len_big(t_bigint *elephant)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (i < BIGINT_SIZE)
	{
		if (elephant->bigint[i])
			len = i + 1;
		i++;
	}
	return (len);
}
