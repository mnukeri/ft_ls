#include "ft_ls.h"

void        ft_pr_perm(unsigned int perms, int direc)
{
    int     p;
    int     *bin;
    unsigned int     *bin_arr;
    int     k;
    char    *perm_arr;

    if (!(bin = (int*)malloc(sizeof(int) * 17)))
        return ;
    ft_memset(bin,48,17);
    if (!(bin_arr = (unsigned int*)malloc(sizeof(unsigned int) * 17)))
        return ;
    p = 0;
    k = 65536;
    while (p < 17)
    {
        bin_arr[p] = k;
        k /= 2;
        p++;
    }
    p = 0;
    if (direc == 1)
        bin[7] = 1;
    while (p <= 16)
    {
        if (perms > bin_arr[p])
        {
            perms -= bin_arr[p];
            bin[p] = 1;
        }
        p++;        
    }
    perm_arr = "drwxrwxrwx";
    p = 7;
    k = 0;
    while (p <= 16)
    {
        if (bin[p] == 1)
            ft_putchar((int)perm_arr[k]);
        if (bin[p] == 0)
            ft_putchar('-');
        k++;
        p++;
    }
}