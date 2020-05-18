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

int		ls_process_R_count(char **dir)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	int				m;
	char			*st1;

	if (!dir)
		return (0);
	m = 1;
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
			st1 = ft_strnew(ft_strlen(*dir));
			st1 = ft_strcpy(st1, *dir);
			st1 = ft_strjoin(st1, "/");
			st1 = ft_strjoin(st1, pDirent->d_name);
			if (!(m += ls_process_R_count(&st1)))
				return (0);
			ft_strclr(st1);
		}
	}
	closedir(pDir);
	return (m);
}