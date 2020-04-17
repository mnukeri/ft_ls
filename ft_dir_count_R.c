/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:23:42 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 15:52:55 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_dir_count_R(char **dir)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	int				l;

	if (!dir)
		return (0);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	ft_putendl("fdc_R we're..");
	l = 0;
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (ft_dir_check(pDirent->d_name) == 1)
			l += 1;//ft_dir_count(pDirent);
		l += 1;
	}
	closedir(pDir);
	return (l);
}
