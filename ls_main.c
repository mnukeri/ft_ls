/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:38 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 16:15:34 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	*path1;
	int		k;

	if (argc < 1)
		return (0);
	k = 0;
	if (argc == 1)
	{
		path1 = ".";
		ls_process(&path1, k);
		return (0);
	}
	if (argc > 1)
	{
		k = flag_checker(argv);
		if (argc == 2 && argv[1][0] == '-')
			path1 = ".";
		else
		{
			path1 = path_checker(argv);
			if (!path1)
				return (0);
		}
		if (ls_process(&path1, k) != 1)
		{
			ft_putendl("Could not finish the LS process, harde ntwana;");
			return (0);
		}
	}
	return (0);
}
