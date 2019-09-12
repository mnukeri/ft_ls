/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:06:02 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 15:26:13 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_checker(char **input)
{
	int		p;

	if (!(input))
	{
		ft_putendl("Could not read from the input into 'path_checker' func, harde ntwana;");
		return (0);
	}
	p = 1;
	while (input[p])
	{
		if (input[p][0] == '-')
			p++;
		else
			return ((char *)input[p]);
	}
	ft_putendl("Could not find a 'path' after reading the input into 'path_checker' func, harde ntwana;");
	return (0);
}
