/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:25:34 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/30 15:34:11 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ls_process(char **dir)
{
	char	**s;
	int		k;

	if (dir == NULL)
		return (0);
	if ((k = ft_dir_count(dir)) < 0)
	{
		ft_putendl("Could not count elements in directory, harde ntwana;");
		return (0);
	}
	if (!(s = ft_dir_copy(dir, k)))
	{
		ft_putendl("Could not copy elements into array, harde ntwana;");
		return (0);
	}
	if (ft_sorter(s) != 1)
	{
		ft_putendl("Could not sort array of directory elements, harde ntwana;");
		return (0);
	}
	if (ft_content_display(s) != 1)
	{
		ft_putendl("Could not display elements after sorting, harde ntwana;");
	}
	free(s);
	return (1);
}
