#include "libft.h"

long long int		ft_abs_ll(int nbr)
{
	long long int	tmp;

	tmp = nbr;
	if (nbr < 0)
		return (-tmp);
	else
		return (tmp);
}
