/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:38 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/10 17:11:49 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	**path;
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
	if (argc == 2)
	{
		if (argv[1][0] == '-')
		{
			k = flag_checker(argv[1]);
			path1 = ".";
		}
		if (argv[1][0] != '-')
			path1 = argv[1];
		if (ls_process(&path1, k) != 1)
		{
			ft_putendl("Could not work with a single input, harde ntwana;");
			return (0);
		}
	}
	if (argc > 1 && argv[2][0] != '-')
	{
		path = &argv[2];
		if (ls_process(path, k) != 1)
		{
			ft_putendl("Could not finish the LS process, harde ntwana;");
			return (0);
		}
	}
	return (0);
}
