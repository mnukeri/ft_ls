#include "ft_ls.h"

int         ft_dir_strlen(char **dir)
{
    struct dirent   *pDirent;
    DIR             *pDir;
    size_t            len;

    if (!dir)
        return (0);
    if ((pDir = opendir(*dir)) == NULL)
        return (0);
    len = 0;
    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (ft_strlen(pDirent->d_name) > len)
            len = ft_strlen(pDirent->d_name);
    }
    closedir(pDir);
    return (len);
}