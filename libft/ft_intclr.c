#include "libft.h"

void	ft_intclr(int *inte)
{
	int		p;

	if (inte == 0)
		return ;
	p = 0;
	while (inte[p])
		inte[p++] = 0;
}
