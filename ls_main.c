/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:38 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/24 17:33:56 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char		**s;
	int			k;

	if (argc < 2)
		return (0);
	if ((k = ft_dir_count(&argv[1])) < 0)
	{
		ft_putendl("Could not count elements in directory;");
		return (0);
	}
	if (!(s = ft_dir_copy(&argv[1], k)))
	{
		ft_putendl("Could not copy elements into array;");
		return (0);
	}
	if (ft_sorter(s) != 1)
	{
		ft_putendl("Could not sort;");
		return (0);
	}
	if (ft_content_display(s) != 1)
	{
		ft_putendl("Could not display content after sorting");
		return (0);
	}
	free(s);
	return (0);
}
