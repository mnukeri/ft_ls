/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:14:07 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/30 14:53:22 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			k;
	unsigned char	*st;
	size_t			m;

	st = (unsigned char *)str;
	k = 0;
	while (k < n && st[k])
	{
		if (st[k] == (unsigned char)c)
			return ((char *)&st[k]);
		else
			k++;
	}
	m = ft_strlen(str);
	if (c == '\0')
		return ((char *)&st[m]);
	return (0);
}
