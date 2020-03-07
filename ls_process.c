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

int		ls_process(char **dir, int k)
{
	char	**s;

	if (dir == NULL)
		return (0);
	ft_putstr("k: ");
	ft_putnbr(k);
	ft_putchar('\n');
	if (!(s = ft_diff_flag(dir, k)))
	{
		ft_putendl("Could not copy flag filtered elements into the array, harde ntwana;");
		return (0);
	}

	//code is seg'ing from here on MAC;
	if (k == 3)
	{
		if (ft_sorter_t(s, dir) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}
	else if (k == 2)
	{
		if (ft_sorter_l(s, dir) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}
	else
	{
		if (ft_sorter(s, dir, k) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}
	
	ft_putendl("starting fcd..");
	if (ft_content_display(s, k) != 1)
	{
		ft_putendl("Could not display elements after sorting, harde ntwana;");
		return (0);
	}
	ft_strdel(s);
	return (1);
}
