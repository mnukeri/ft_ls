/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:38 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/01 18:08:31 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**path;
	char	*path1;
	int		k;
	int		p;

	if (argc < 1)
	{
		ft_putendl("PLease gooi in a proper path");
		return (0);
	}
	k = flag_checker(argv);
	path = path_checker(argv);
	if(argc == 1)
	{
		path1 = ".";
		ls_process(&path1, k);
		return (0);
	}
	p = 0;
	while (path[p])
	{
		if (ls_process(&path[p], k) != 1)
		{
			ft_putendl("Could not finish the LS process, harde ntwana;");
			return (0);
		}
		p++;
	}
	free(path);
	return (0);
}
