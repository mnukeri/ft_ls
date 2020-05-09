#include "ft_ls.h"

int				ls_process_R(char **dir, char **fin_s, int *m2)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			*st1;
	char			**s;
	int				len;
	int				m;
	int				k;

	if (!dir)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(ft_dir_count(dir) + 1)))
		return (0);
	len = ft_dir_strlen(dir);
	m = 0;
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (ft_strcmp(pDirent->d_name, *dir) != 1)
			continue ;
		if (pDirent->d_name[0] == '.')
			continue ;
		if (pDirent->d_type == DT_DIR)
		{
			if (!(s[m] = ft_memalloc(len + 1)))
				return (0);
			st1 = ft_strnew(ft_strlen(*dir));
			st1 = ft_strcpy(st1, *dir);
			st1 = ft_strjoin(st1, "/");
			st1 = ft_strjoin(st1, pDirent->d_name);
			if (ls_process_R(&st1, fin_s, (int*)m2) != 1)
				return (0);
			++(*m2);
		}
        if (!(s[m] = ft_memalloc(len + 1)))
            return (0);
        ft_strcpy(s[m], (char*)pDirent->d_name);
        m++;
	}
	closedir(pDir);
	s[m] = NULL;
	m = 0;
	while (s[m])
		m++;
	if (m != 0)
	{
		if (ft_sorter(s, dir, 0) != 1)
			return (0);
	}
	if (!(st1 = ft_strnew(1)))
		return (0);
	st1 = ft_strjoin(st1, *dir);
	if (m != 0)
	{
		k = 0;
		while (k < m && s[k])
		{
			st1 = ft_strjoin(st1, "`");
			st1 = ft_strjoin(st1, s[k]);
			k++;
		}
	}
	else
		st1 = ft_strjoin(st1,"`");
    if (!(fin_s[*m2] = ft_memalloc(ft_strlen(st1) + 1)))
        return (0);
    ft_strcpy(fin_s[*m2], st1);
	ft_strdel(s);
	return (1);
}