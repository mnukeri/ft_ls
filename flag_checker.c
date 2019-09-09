/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:18:11 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/09 18:56:44 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		flag_checker(char *input)
{
	int		p;

	p = 0;
	if (input[p] == '-')
	{
		p++;
		if (input[p] == 'a')
			return (1);
		if (input[p] == 'l')
			return (2);
		if (input[p] == 't')
			return (3);
		if (input[p] == 'r')
			return (4);
		if (input[p] == 'R')
			return (5);
	}
	return (0);
}
