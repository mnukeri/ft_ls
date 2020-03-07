#include "ft_ls.h"

char		**ft_k_5(char **str) //-R
{
	struct dirent	*pDirent;
	DIR				*pDir;

	if (!str)
		return (NULL);
	if ((pDir = opendir(*str)) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		/*if (str[p][1] == '.')
			p++;
		if (ft_strlen(str[p]) > 1 && str[p][0] == '.')
			p++;*/
		if (ft_dir_check(pDirent->d_name) == 1)
		{
			ft_putstr(pDirent->d_name);
			ft_putendl(":");
			ft_putendl("***   ***   ***");
			ls_process_R((char**)pDirent->d_name);
			//add recursion..
			ft_putendl("***   ***   ***");
			ft_putchar('\n');
			ft_putchar('\n');
		}
	}
	closedir(pDir);
	return (0);
}

char		**ft_k_3(char **str, int dc) //-t
{
	struct stat		filestat;
	struct dirent	*pDirent;
	DIR				*pDir;
	int				m;
	char			**s;
	char			*st;

	if (!str)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
		return (0);
	if ((pDir = opendir(*str)) == NULL)
		return (0);
	m = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] != '.')
		{
			stat(pDirent->d_name, &filestat);
			st = ft_strnew(1);
			st = ft_strjoin(st, (char*)pDirent->d_name);
			st = ft_strjoin(st, "`");
			st = ft_strjoin(st, ft_itoa(filestat.st_mtime));
			st = ft_strjoin(st, "`");
			st = ft_strjoin(st, ctime(&filestat.st_mtime));
			ft_putstr("st: ");
			ft_putstr(st);
			ft_putendl("|");
			if (!(s[m] = ft_memalloc(ft_strlen(st) + 1)))
				return (0);
			ft_strcpy(s[m], st);
			m++;
			ft_strclr(st);
		}
	}
	closedir(pDir);
	return (s);
}

int			ft_fcl(char **str)
{
	struct stat		filestat;
	struct dirent	*pDirent;
	DIR				*pDir;
	int				len;

	if (!str)
		return (0);
	if ((pDir = opendir(*str)) == NULL)
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

char		**ft_k_2(char **str, int dc) //-l
{
	struct stat     filestat;
	struct passwd	*info;
	struct group	*info_g;
    struct dirent   *pDirent;
    DIR             *pDir;
    int             k;
	int				m;
	int				fs_col_len;
    char            *st;
    char            **s;
	char			*finperms;
	
	if (!str)
        return (0);
	fs_col_len = ft_fcl(str);
	if (!(s = (char**)ft_memalloc_2d(dc + 1)))
        return (0);
	if ((pDir = opendir(*str)) == NULL)
        return (0);
	m = 0;
    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (pDirent->d_name[0] == '.')
        {
            continue;
        }
        else
        {
			if (!(st = ft_strnew(1)))
				return (0);
			//find out why permissions are not printing anymore..
        	stat(pDirent->d_name, &filestat);
			k = (S_ISDIR(filestat.st_mode)) ? 1 : 0;
			ft_putstr("k: ");
			ft_putnbr(k);
			ft_putendl("|");
			finperms = ft_pr_perm(filestat.st_mode,k);
			ft_putstr("finperms: ");
			ft_putendl(finperms);
        	st = ft_strjoin(st, finperms);
        	st = ft_strjoin(st," ");
			st = ft_strjoin(st, ft_itoa(filestat.st_nlink));
        	st = ft_strjoin(st," ");
			info = getpwuid(filestat.st_uid);
        	st = ft_strjoin(st, info->pw_name);
        	st = ft_strjoin(st," ");
			info_g = getgrgid(filestat.st_gid);
        	st = ft_strjoin(st, info_g->gr_name);
        	//st = ft_strjoin(st," ");
			k = ft_dig(filestat.st_size);
			while (k <= fs_col_len)
			{
				st = ft_strjoin(st," ");
				k++;
			}
        	st = ft_strjoin(st , ft_itoa(filestat.st_size));
        	st = ft_strjoin(st," ");
        	st = ft_strjoin(st, ft_strsub(ctime(&filestat.st_mtime),4,12));
        	st = ft_strjoin(st," ");
        	st = ft_strjoin(st, (char*)pDirent->d_name);
			//since s is a **, try storing each thing in its own lot..
			if (!(s[m] = ft_memalloc(ft_strlen(st) + 1)))
				return (0);
			ft_strcpy(s[m], st);
			m++;
        }
    }
	closedir(pDir);
	return (s); 
}

char    **ft_k_1(char **str, int dc) //-a
{
    struct dirent   *pDirent;
    DIR             *pDir;
    char            **s;
    int             m;

	if (!str)
		return (0);
     if (!(s = (char**)ft_memalloc_2d(dc + 1)))
        return (0);
    if ((pDir = opendir(*str)) == NULL)
        return (0);
    m = 0;
	while ((pDirent = readdir(pDir)) != NULL)
    {
        if (!(s[m] = ft_memalloc(ft_strlen(pDirent->d_name) + 1)))
            return (0);
        ft_strcpy(s[m], (char*)pDirent->d_name);
		ft_putendl(s[m]);
        m++;
    }
	closedir(pDir);
	return (s);
}

char    **ft_k_0(char **str, int dc) //default
{
    struct dirent   *pDirent;
    DIR             *pDir;
    char    **s;
    int     m;

	if (str == NULL)
		return (0);
    if (!(s = (char**)ft_memalloc_2d(dc + 1)))
        return (0);
    if ((pDir = opendir(*str)) == NULL)
        return (0);
    m = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (pDirent->d_name[0] != '.')
        {
            if (!(s[m] = ft_memalloc(ft_strlen(pDirent->d_name))))
                return (0);
            s[m] = ft_strdup((char*)pDirent->d_name);
			ft_putstr("s[");
			ft_putnbr(m);
			ft_putstr("]: ");
			ft_putstr(s[m]);
			ft_putstr("| len: ");
			ft_putendl(ft_itoa(ft_strlen(pDirent->d_name)));
        	m++;
        }
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
	dir_count = ft_dir_count(dir, k);
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
