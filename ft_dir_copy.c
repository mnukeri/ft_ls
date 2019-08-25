/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:18:32 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/24 17:09:01 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_dir_copy(char **dir, int k)
{
	struct dirent	*pDirent;
	DIR				*pDir;
	char			*st;
	char			**s;

	if (!(st = ft_memalloc(k)))
		return (0);
	ft_bzero(st, k);
	if ((pDir = opendir(*dir)) == NULL)
		return (0);
	while ((pDirent = readdir(pDir)) != NULL)
	{
		ft_strcat(st, pDirent->d_name);
		ft_strcat(st, " ");
	}
	if (!(s = ft_strsplit(st, ' ')))
	{
		ft_putendl("Could not split 'directory names' string");
		return (0);
	}
	return (s);
}
