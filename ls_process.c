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
	if (!(s = ft_diff_flag(dir, k)))
	{
		ft_putendl("Could not copy flag filtered elements into the array, harde ntwana;");
		return (0);
	}

	if (k == 3)
	{
		if (ft_sorter_t(s) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}
	else if (k == 2)
	{
		if (ft_sorter_l(s) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}
	else
	{
		if (ft_sorter(s) != 1)
		{
			ft_putendl("Could not sort array of directory elements, harde ntwana;");
			return (0);
		}
	}

	if (ft_content_display(s, k) != 1)
	{
		ft_putendl("Could not display elements after sorting, harde ntwana;");
		return (0);
	}
	ft_strdel(s);
	return (1);
}
