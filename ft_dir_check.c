#include "ft_ls.h"

int         ft_dir_check(const char *st)
{
    DIR             *pDir;
    //struct dirent   *pDirent;
    int             k;

    if ((pDir = opendir(st)) != NULL)
    {
        k = 1;
        closedir(pDir);
    }
    else
        k = 0;
    //while ((pDirent = readdir(pDir)) != NULL)
    //    ft_putendl(pDirent->d_name);
    return (k);
}