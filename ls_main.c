/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:37:38 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/30 15:32:12 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	char	*path;

	if (argc < 1)
	{
		ft_putendl("PLease gooi in a proper path");
		return (0);
	}
	if(argc == 1)
	{
		path = ".";
		ls_process(&path);
		return (0);
	}
	if (ls_process(&argv[1]) != 1)
	{
		ft_putendl("Could not finish the LS main, mayn;");
		return (0);
	}
}
