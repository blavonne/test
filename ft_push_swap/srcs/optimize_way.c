#include "checker.h"


void			merge_r(unsigned char *a, unsigned char *b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (a[i] != PA && b[j] != a[0])
	{
		i = 0;
		while (a[i] != PA && b[j] != a[0])
		{
			if (b[j] == RB && a[i] == RA)
			{
				b[j++] = RR;
				a[i] = 0;
			}
			if (b[j] == RRB && a[i] == RRA)
			{
				b[j++] = RRR;
				a[i] = 0;
			}
			i++;
		}
		(b[j] == a[0]) ? 0 : j++;
	}
}

void			reset_size(unsigned char *b, t_vector *way)
{
	int		i;
	int		j;

	i = 0;
	while (i < way->next && way->next > 1)
	{
		if (b[i] == 0)
		{
			j = i;
			while (j + 1 < way->next)
			{
				b[j] = b [j + 1];
				j++;
			}
			way->next--;
		}
		i++;
	}
}

void			optimize_way(t_vector *way)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	a = 0;
	b = way->arr;
	while (i < way->next)
	{
		if (b[i] == RA || b[i] == RRA)
		{
			a = &b[i];
			break ;
		}
		i++;
	}
	a ? merge_r(a, b) : 0;
	a ? reset_size(b, way) : 0;
}
