/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:16:11 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/28 16:57:31 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int p;
	int k;

	if (s1 == NULL || s2 == NULL)
		return (0);
	p = 0;
	while (s1[p] != '\0' && s2[p] != '\0' && s1[p] == s2[p])
	{
		p++;
	}
	k = (unsigned char)s1[p] - (unsigned char)s2[p];
	if (k == 0)
		return (1);
	return (0);
}
