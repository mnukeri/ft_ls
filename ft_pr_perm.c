#include "ft_ls.h"

char        *ft_pr_perm(unsigned int perms, int direc)
{
    int             p;
    unsigned int    *bin;
    unsigned int    *bin_arr;
    int             k;
    char            *perm_arr;
    char            *finperms;

    ft_putstr("perms: ");
    ft_putnbr(perms);
    ft_putstr("|");
    if (!(bin = ft_memalloc_int(17)))
        return (NULL);
    ft_memset_int(bin,0,17);
    if (!(bin_arr = ft_memalloc_int(17)))
        return (NULL);
    ft_memset_int(bin_arr,0,17);
    p = 0;
    k = 65536;
    while (p < 17)
    {
        bin_arr[p] = k;
        k /= 2;
        p++;
    }
    p = 16;
    while (p >= 0)
    {
        bin[p] = (perms % 2) ? 1 : 0;
        perms /= 2;
        p--;        
    }
    perm_arr = "drwxrwxrwx";
    if (!(finperms = ft_memalloc(11)))
        return (NULL);
    k = 0;
    p = 7;
    bin[p] = (direc == 1) ? 1 : 0;
    ft_putstr(" bin[7]: ");
    ft_putnbr(bin[p]);
    ft_putendl("|");
    while (p < 17)
    {
        if (bin[p] == 1)
            finperms[k] = (int)perm_arr[k];
        if (bin[p] == 0)
            finperms[k] = '-';
        k++;
        p++;
    }
    /*ft_intclr((int*)bin);
    ft_intclr((int*)bin_arr);
    ft_strclr(perm_arr);
    free(bin);
    free(bin_arr);
    free(perm_arr);*/
    return (finperms);
}