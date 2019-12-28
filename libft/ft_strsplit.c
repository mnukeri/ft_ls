/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:41:00 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/18 13:50:25 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *str, char c)
{
	int		p;
	int		i;
	int		j;
	char	**y;

	if (!str || !(y = (char**)malloc(sizeof(char*) * ft_wc(str, c))))
		return (NULL);
	i = 0;
	p = 0;
	while (str[p] && i < ft_wc(str, c))
	{
		while (str[p] == c && str[p])
			p++;
		j = 0;
		while (str[p + j] != '\0' && str[p + j] != c)
			j++;
		y[i] = ft_memalloc(j + 1);
		y[i] = ft_strsub(str, p, (j + 1));
		y[i][j] = '\0';
		p = p + j;
		i++;
	}
	y[i] = NULL;
	return (y);
}
