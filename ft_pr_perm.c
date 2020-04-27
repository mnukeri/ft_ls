#include "ft_ls.h"

char        *ft_pr_perm(unsigned int perms, int direc)
{
    int             p;
    char            **bin;
    unsigned int    *bin_arr;
    char            *finperms;
    int             perms_2;
    int             perms_3;
    int             p_2;

    perms_2 = perms;
    perms_3 = perms;
    p = 0;
    //ft_putstr("perms: ");
    //ft_putendl(ft_itoa(perms));
    while (perms_2)
    {
        perms_2 /= 8;
        p++;
    }
    p_2 = p;
    if (!(bin_arr = ft_memalloc_int(p)))
        return (NULL);
    p--;
    while (p >= 0)
    {
        bin_arr[p] = perms_3 % 8;
        /*ft_putstr("bin[");
        ft_putnbr(p);
        ft_putstr("]: ");
        ft_putendl(ft_itoa(bin_arr[p]));*/
        perms_3 /= 8;
        p--;
    }
    if (!(bin = (char**)ft_memalloc_2d(8)))
        return (NULL);
    ft_memset(bin,0,9);
    bin[0] = "---";
    bin[1] = "--x";
    bin[2] = "-w-";
    bin[3] = "-wx";
    bin[4] = "r--";
    bin[5] = "r-x";
    bin[6] = "rw-";
    bin[7] = "rwx";
    if (!(finperms = ft_memalloc(11)))
        return (NULL);
    p = p_2 - 3;
    finperms[0] = (direc == 1) ? 'd' : '-';
    while (p < p_2 && bin_arr[p])
    {
        if (bin_arr[p] == 0)
            finperms = ft_strjoin(finperms, bin[0]);
        if (bin_arr[p] == 1)
            finperms = ft_strjoin(finperms, bin[1]);
        if (bin_arr[p] == 2)
            finperms = ft_strjoin(finperms, bin[2]);
        if (bin_arr[p] == 3)
            finperms = ft_strjoin(finperms, bin[3]);
        if (bin_arr[p] == 4)
            finperms = ft_strjoin(finperms, bin[4]);
        if (bin_arr[p] == 5)
            finperms = ft_strjoin(finperms, bin[5]);
        if (bin_arr[p] == 6)
            finperms = ft_strjoin(finperms, bin[6]);
        if (bin_arr[p] == 7)
            finperms = ft_strjoin(finperms, bin[7]);
        p++;
    }
    /*ft_intclr((int*)bin);
    ft_intclr((int*)bin_arr);
    ft_strclr(perm_arr);
    free(bin);
    free(bin_arr);
    free(perm_arr);*/
    //ft_putstr("finperms: ");
    //ft_putendl(finperms);
    return (finperms);
}