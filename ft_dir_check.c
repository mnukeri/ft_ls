#include "ft_ls.h"

int         ft_dir_check(char *st)
{
    DIR             *pDir;

    if ((pDir = opendir(st)) == NULL)
        return (0);
    closedir(pDir);
    return (1);
}