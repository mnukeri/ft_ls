/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:30:16 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/30 15:17:15 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sorter_l(char **s)
{
	int		p;
	int		n;
	char	**s1;
	char	**s2;
	int		steps;

	if (s == NULL)
		return (0);
	p = 1;
	steps = 0;
	while (s[p])
	{
		s1 = ft_strsplit(s[p - 1],' ');
		s2 = ft_strsplit(s[p],' ');
		n = ft_strcmp(s1[8], s2[8]);
		if (n == 1)
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
