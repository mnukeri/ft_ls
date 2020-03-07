#include "libft.h"

void	**ft_memalloc_2d(size_t size)
{
	char	**s;

	s = (char **)malloc(sizeof(char *) * size);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size);
	return ((void**)s);
}
