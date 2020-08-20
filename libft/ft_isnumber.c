#include "libft.h"

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
