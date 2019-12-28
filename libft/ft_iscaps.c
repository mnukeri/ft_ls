#include "libft.h"

int		ft_iscaps(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
