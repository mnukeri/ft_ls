/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:30:16 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/24 16:33:03 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sorter(char **s)
{
	int		p;
	int		k;
	int		steps;

	if (s == NULL)
		return (0);
	p = 1;
	steps = 0;
	while (s[p])
	{
		k = ft_strcmp(s[p - 1], s[p]);
		if (k == 1)
		{
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
		}
		p++;
		steps++;
	}
	return (1);
}
