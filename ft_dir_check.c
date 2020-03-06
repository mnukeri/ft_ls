#include "ft_ls.h"

int         ft_dir_check(char *st)
{
    DIR             *pDir;
    int             k;

    if ((pDir = opendir(st)) == NULL)
        k = 0;
    else
        k = 1;
    closedir(pDir);
    return (k);
}