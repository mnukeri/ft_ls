#include "ft_ls.h"

int        ft_flag_L(char **dir)
{
    struct stat     filestat;
    struct dirent   *pDirent;
    DIR             *pDir;
    int             k;

    if ((pDir = opendir(*dir)) == NULL)
        return (0);
    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (pDirent->d_name[0] == '.')
        {
            continue;
        }
        else
        {        
        if (ft_dir_check(pDirent->d_name) == 1)
            k = 1;
        else
            k = 0;
        stat(pDirent->d_name, &filestat);
        ft_pr_perm(filestat.st_mode, k);
        ft_putstr("   ");
        ft_putnbr(filestat.st_nlink);
        ft_putstr("   ");
        ft_putnbr(filestat.st_uid);
        ft_putstr("   ");
        ft_putnbr(filestat.st_gid);
        ft_putstr("   ");
        ft_putnbr(filestat.st_size);
        ft_putstr("   ");
        ft_putstr(ctime(&filestat.st_ctime));
        ft_putstr("   ");
        ft_putendl(pDirent->d_name);
        }
    }
    return (1);
}
//i am to create a decimal to binary converter.. as well as that it should have an identifier that tis a dir or not..
//in this manner, also check how to convert the other values..
//at this rate, we are creating more functions..