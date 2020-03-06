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
	char	**s;
	int		dir_count;

	if (dir == NULL)
		return (0);
	if ((dir_count = ft_dir_count(dir, 5)) < 1)
	{
		ft_putendl("Could not count elements in directory, harde ntwana;");
		return (0);
	}
	if (!(s = ft_dir_copy(dir, dir_count)))
	{
		ft_putendl("Could not copy elements into array, harde ntwana;");
		return (0);
	}
	/*if (ft_sorter(s) != 1)
	{
		ft_putendl("Could not sort array of directory elements, harde ntwana;");
		return (0);
	}*/
	if (ft_content_display(s,0) != 1)
	{
		ft_putendl("Could not display elements after sorting, harde ntwana;");
		return (0);
	}
	free(s);
	return (1);
}
