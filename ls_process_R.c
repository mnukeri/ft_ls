/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:25:34 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/10 17:11:46 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_process_R(char **dir)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			*st1;
	char			**s;
	int				len;
	int				m;

	if (!dir)
		return (0);
	if (!(s = (char**)ft_memalloc_2d(ft_dir_count(dir))))
		return (0);
	len = ft_dir_strlen(dir);
	m = 0;
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	//add path links to locations when passing them around..
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (ft_strcmp(pDirent->d_name, *dir) != 1)
			continue ;
		if (pDirent->d_name[0] == '.')
			continue ;
		if (ft_dir_check(pDirent->d_name) == 1)
		{
			st1 = ft_strnew(ft_strlen(*dir));
			st1 = ft_strcpy(st1, *dir);
			st1 = ft_strjoin(st1, "/");
			st1 = ft_strjoin(st1, pDirent->d_name);
			if (ls_process_R(&st1) != 1)
				return (0);
			ft_strclr(st1);
		}
		else
		{
			if (!(s[m] = ft_memalloc(len + 1)))
				return (0);
			ft_strcpy(s[m], (char*)pDirent->d_name);
			m++;
		}
	}
	s[m] = NULL;
	if (ft_sorter(s, dir, 0) != 1)
		return (0);
	ft_putstr(*dir);
	ft_putendl(":");
	ft_putendl("***   ***   ***");
	if (ft_content_display(s, dir, 0) != 1)
		return (0);
	ft_putendl("***   ***   ***");
	ft_putchar('\n');
	ft_strdel(s);
	return (1);
}
