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

	if (s == NULL)
		return (0);
	dc = ft_dir_count(dir, k);
	ft_putstr("dc_a: ");
	ft_putnbr(dc);
	ft_putchar('\n');
	p = 1;
	steps = 0;
	while (s[p]) //keeps seg'ing when reaches fcd.o
	{
		n = ft_strcmp(s[p - 1], s[p]);
		ft_putstr("n: ");
		ft_putnbr(n);
		ft_putstr("| p: ");
		ft_putnbr(p - 1);
		ft_putchar(' ');
		ft_putstr(ft_itoa(p));
		ft_putstr("\t| s[p-1]: ");
		ft_putstr(s[p - 1]);
		ft_putstr("\t| s[p]: ");
		ft_putendl(s[p]);
		if (n == 1)
		{
			if (ft_array_swap(s[p - 1], s[p]) != 1)
				return (0);
			p = 0;
			ft_putendl("back to 0..");
		}
		p++;
		steps++;
	}
	ft_putendl("exit sort_a..");
	return (1);
}