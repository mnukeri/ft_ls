/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:28:40 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/08 17:27:05 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			k;
	size_t			p;
	unsigned char	*st;
	unsigned char	*s;

	if (n == 0)
		return (0);
	st = (unsigned char *)s1;
	s = (unsigned char *)s2;
	k = 0;
	p = 1;
	while (st[k] == s[k] && p != n)
	{
		k++;
		p++;
	}
	return (st[k] - s[k]);
}
