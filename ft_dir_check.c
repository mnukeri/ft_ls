#include "ft_ls.h"

int         ft_dir_check(char *st)
{
    DIR             *pDir;
    //struct dirent   *pDirent;
    int             k;

    if ((pDir = opendir(st)) == NULL)
        k = 0;
    else
        k = 1;
    //while ((pDirent = readdir(pDir)) != NULL)
    //    ft_putendl(pDirent->d_name);
    closedir(pDir);
    return (k);
}