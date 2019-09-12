/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:28:18 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 16:15:19 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_k_0(char **str)
{
	int		p;

	if (str == NULL)
		return (0);
	p = 0;
	while (str[p])
	{
		if (s[p][0] != '.')
			ft_putendl(str[p]);
		p++;
	}
	return (1);
}

int			ft_content_display(char **s, int k)
{
	int		p;

	if (s == NULL)
		return (0);
	p = 0;
	if (k == 0)
	{
		if (ft_
	}
	if (k == 1)
	{
		while (s[p])
			ft_putendl(s[p++]);
	}
	return (1);
}
