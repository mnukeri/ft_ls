/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:18:11 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 15:19:45 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag_checker(char **input)
{
	int		p;

	p = 1;
	if (input[p][0] == '-')
	{
		if (input[p][1] == 'a')
			return (1);
		if (input[p][1] == 'l')
			return (2);
		if (input[p][1] == 't')
			return (3);
		if (input[p][1] == 'r')
			return (4);
		if (input[p][1] == 'R')
			return (5);
	}
	return (0);
}
