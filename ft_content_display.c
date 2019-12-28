/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:28:18 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 16:15:19 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_k_5(char **str)
{
	int		p;

	if (!str)
		return ;
	p = 0;
	while (str[p])
	{
		/*if (str[p][1] == '.')
			p++;
		if (ft_strlen(str[p]) > 1 && str[p][0] == '.')
			p++;*/
		if (ft_dir_check(str[p]) == 1)
		{
			ft_putchar('/');
			ft_putendl(str[p]);
			ft_putendl("***   ***   ***");
			ls_process_R(&str[p], 0);
			ft_putendl("***   ***   ***");
			ft_putchar('\n');
			ft_putchar('\n');
		}
		p++;
	}
}

static void	ft_k_4(char **str)
{
	int		p;

	if (!str)
		return ;
	p = 0;
	while (str[p])
		p++;
	p--;
	while (p >= 0)
	{
		if (str[p][0] != '.')
			ft_putendl(str[p]);
		p--;
	}
}

static void		ft_k_2(char **str)
{
	struct stat     filestat;
    struct dirent   *pDirent;
    DIR             *pDir;
    int             k;
// i am going to have to store the correct order before hand so that i can sort..;
    if ((pDir = opendir(*str)) == NULL)
        return ;
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
        	ft_putstr("  ");
        	ft_putnbr(filestat.st_nlink);
        	ft_putstr("  ");
        	ft_putnbr(filestat.st_uid);
        	ft_putstr("  ");
        	ft_putnbr(filestat.st_gid);
        	ft_putstr("  ");
        	ft_putnbr(filestat.st_size);
        	ft_putstr("  ");
        	ft_putstr(ctime(&filestat.st_ctime));
        	ft_putstr("  ");
        	ft_putendl(pDirent->d_name);
        }
    }
}

static void	ft_k_1(char **str)
{
	int		p;

	if (!str)
		return ;
	p = 0;
	while (str[p])
	{
		ft_putendl(str[p]);
		p++;
	}
}

static void	ft_k_0(char **str)
{
	int		p;

	if (str == NULL)
		return ;
	p = 0;
	while (str[p])
	{
		if (str[p][0] != '.')
			ft_putendl(str[p]);
		p++;
	}
}



int			ft_content_display(char **s, int k)
{
	if (s == NULL)
		return (0);
	if (k == 0)
		ft_k_0(s);
	if (k == 1)
		ft_k_1(s);
	if (k == 2)
		ft_k_2(s);
	if (k == 4)
		ft_k_4(s);
	if (k == 5)
		ft_k_5(s);
	return (1);
}
