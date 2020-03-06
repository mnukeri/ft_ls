#include "libft.h"

int     ft_dig(int dig)
{
    int     k;

    k = 0;
    while (dig != 0)
    {
        dig /= 10;
        k++;
    }
    return (k);
}