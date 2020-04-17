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

int			ft_dir_count(char **dir)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	int				l;

	if (!dir)
		return (0);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	l = 0;
	while ((pDirent = readdir(pDir)) != NULL)
		l += 1;
	closedir(pDir);
	/*ft_putstr("fdc: ");
	ft_putendl(ft_itoa(l));
	ft_putendl("fdc we're.. here");*/
	return (l);
}
