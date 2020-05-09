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

int			ft_sorter(char **s, char **dir, int k)
{
	int		p;
	int		n;
	int		dc;
	int		steps;

	if (!s)
		return (0);
	k /= 2;
	dc = ft_dir_count(dir);
	p = 1;
	steps = 0;
	while (p < dc && s[p])
	{
		n = ft_strcmp(s[p - 1], s[p]);
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