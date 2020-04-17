#include "ft_ls.h"

int     ft_pDirent_reader(DIR *pDir)
{
    struct dirent   *pDirent;

    if (!pDir)
        return (0);
    while ((pDirent = readdir(pDir)) != NULL)
        ft_putendl(pDirent->d_name);
    return (1);
}