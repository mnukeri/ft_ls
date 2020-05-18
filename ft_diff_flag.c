#include "ft_ls.h"

char		**ft_k_5(char **dir) //-R
{
	char	**s;
	char	**s1;
	int		p;
	int		len;
	int		*m;

	if (dir == NULL)
		return (0);
	if (!(s1 = (char**)ft_memalloc_2d(ls_process_R_count(dir) + 1)))
		return (0);
	p = 0;
	m = &p;
	if (ls_process_R(dir, s1, m) != 1)
		return (0);
	++(*m);
	s1[*m] = NULL;
	p = 0;
	len = 0;
	while (s1[p])
	{
		if (ft_strlen(s1[p]) > (size_t)len)
			len = ft_strlen(s1[p]);
		p++;
	}
	if (!(s = (char**)ft_memalloc_2d(ls_process_R_count(dir) + 1)))
		return (0);
	p = 0;
	while (p < ls_process_R_count(dir) && s1[p])
	{
		if (!(s[p] = ft_memalloc(len + 1)))
			return (0);
		ft_strcpy(s[p], s1[p]);
		p++;
	}
	//s[p] = NULL;
	ft_strdel(s1);
	return (s);
}

char		**ft_k_3(char **dir, int dc) //-t
{
	struct stat		filestat;
	struct dirent	*pDirent;
	DIR				*pDir;
	int				m;
	char			**s;
	char			*st;

	if (!dir)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
		return (0);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	m = 0;
	ft_putendl("fk3:");
	while ((pDirent = readdir(pDir)) != NULL)
	{
			stat(pDirent->d_name, &filestat);
			st = ft_strnew(1);
			st = ft_strjoin(st, (char*)pDirent->d_name);
			st = ft_strjoin(st, "`");
			st = ft_strjoin(st, ft_itoa(filestat.st_mtime));
			st = ft_strjoin(st, "`");
			st = ft_strjoin(st, ft_strsub(ctime(&filestat.st_mtime), 4, 12));
			/*ft_putstr("st: ");
			ft_putstr(st);
			ft_putendl("|");*/
			if (!(s[m] = ft_memalloc(ft_strlen(st) + 1)))
				return (0);
			ft_strcpy(s[m], st);
			m++;
			ft_strclr(st);
	}
	closedir(pDir);
	return (s);
}

int			ft_cl_size(char **dir)
{
	struct stat		filestat;
	struct dirent	*pDirent;
	DIR				*pDir;
	int				len;

	if (!dir)
		return (0);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	len = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		stat(pDirent->d_name,&filestat);
		if (ft_dig(filestat.st_size) > len)
			len = ft_dig(filestat.st_size);
	}
	closedir(pDir);
	return (len);
}

int			ft_cl_links(char **dir)
{
	struct stat		filestat;
	struct dirent	*pDirent;
	DIR				*pDir;
	int				len;

	if (!dir)
		return (0);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	len = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		stat(pDirent->d_name,&filestat);
		if (ft_dig(filestat.st_nlink) > len)
			len = ft_dig(filestat.st_nlink);
	}
	closedir(pDir);
	return (len);
}

char		**ft_k_2(char **dir, int dc) //-l
{
	struct stat     filestat;
	struct passwd	*info;
	struct group	*info_g;
    struct dirent   *pDirent;
    DIR             *pDir;
    int             k;
	int				m;
	int				fs_col_len;
	int				fs_col_links;
    char            *st;
    char            **s;
	char			*finperms;
	
	if (!dir)
        return (0);
	fs_col_len = ft_cl_size(dir);
	fs_col_links = ft_cl_links(dir);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
        return (0);
	if ((pDir = opendir(*dir)) == NULL)
        return (0);
	m = 0;
	ft_putendl("fk2:");
    while ((pDirent = readdir(pDir)) != NULL)
    {
			if (!(st = ft_strnew(1)))
				return (0);
			//find out why permissions are not printing anymore..
        	stat(pDirent->d_name, &filestat);
			k = (S_ISDIR(filestat.st_mode)) ? 1 : 0;
			finperms = ft_pr_perm(filestat.st_mode,k);
        	st = ft_strjoin(st, finperms);
        	st = ft_strjoin(st,"`");
			k = ft_dig(filestat.st_nlink);
			while (k <= fs_col_links)
			{
				st = ft_strjoin(st," ");
				k++;
			}
			st = ft_strjoin(st, ft_itoa(filestat.st_nlink));
        	st = ft_strjoin(st,"`");
			info = getpwuid(filestat.st_uid);
        	st = ft_strjoin(st, info->pw_name);
        	st = ft_strjoin(st,"`");
			info_g = getgrgid(filestat.st_gid);
        	st = ft_strjoin(st, info_g->gr_name);
        	st = ft_strjoin(st,"`");
			k = ft_dig(filestat.st_size);
			while (k <= fs_col_len)
			{
				st = ft_strjoin(st," ");
				k++;
			}
        	st = ft_strjoin(st , ft_itoa(filestat.st_size));
        	st = ft_strjoin(st,"`");
        	st = ft_strjoin(st, ft_strsub(ctime(&filestat.st_mtime),4,12));
        	st = ft_strjoin(st,"`");
        	st = ft_strjoin(st, (char*)pDirent->d_name);
			//ft_putendl("we're here..");
			if (!(s[m] = ft_memalloc(ft_strlen(st) + 1)))
				return (0);
			ft_strcpy(s[m], st);
			//ft_putendl(s[m]);
			//ft_putendl(ft_itoa(m));
			m++;
    }
	s[m] = NULL;
	closedir(pDir);
	return (s); 
}

char    **ft_k_1(char **dir, int dc) //-a
{
    struct dirent   *pDirent;
    DIR             *pDir;
    char            **s;
    int             m;
	int				len;

	if (!dir)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
		return (0);
	len = ft_dir_strlen(dir);
    if ((pDir = opendir(*dir)) == NULL)
        return (0);
    m = 0;
	ft_putendl("fk1:");
	while ((pDirent = readdir(pDir)) != NULL)
    {
        if (!(s[m] = ft_memalloc(len + 1)))
            return (0);
        ft_strcpy(s[m], (char*)pDirent->d_name);
		//ft_putendl(s[m]);
        m++;
    }
	closedir(pDir);
	return (s);
}

char    **ft_k_0(char **dir, int dc) //default
{
    struct dirent   *pDirent;
    DIR             *pDir;
    char    **s;
    int     m;
	int		len;

	if (dir == NULL)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
		return (0);
	len = ft_dir_strlen(dir);
    if ((pDir = opendir(*dir)) == NULL)
        return (0);
    m = 0;
	ft_putendl("fk0:");
	while ((pDirent = readdir(pDir)) != NULL)
	{
            if (!(s[m] = ft_memalloc(len + 1)))
                return (0);
            ft_strcpy(s[m], (char*)pDirent->d_name);
			/*ft_putstr("s[");
			ft_putnbr(m);
			ft_putstr("]: ");
			ft_putstr(s[m]);
			ft_putstr("| len: ");
			ft_putendl(ft_itoa(ft_strlen(pDirent->d_name)));*/
        	m++;
	}
	closedir(pDir);
    return (s);
}



char		**ft_diff_flag(char **dir, int k)
{
    int     dir_count;
    char    **finstr;

	if (dir == NULL || k < 0 || k > 5)
		return (0);
	dir_count = ft_dir_count(dir);
	/*ft_putstr("fdf_dc: ");
	ft_putendl(ft_itoa(dir_count));*/
	if (k == 0 || k == 4)//default
		finstr = ft_k_0(dir, dir_count);
	if (k == 1)//-a
		finstr = ft_k_1(dir, dir_count);
	if (k == 2)//-l
		finstr = ft_k_2(dir, dir_count);
	if (k == 3)//-t
		finstr = ft_k_3(dir, dir_count);
	if (k == 5)//-R
		finstr = ft_k_5(dir);
	return (finstr);
}
