#include "libft.h"

void	**ft_memalloc_2d(size_t size)
{
	unsigned char	**s;

	s = (unsigned char **)malloc(sizeof(char **) * size);
	if (s == NULL)
		return (NULL);
	ft_memset(s, 0, size);
	return ((void **)(s));
}
