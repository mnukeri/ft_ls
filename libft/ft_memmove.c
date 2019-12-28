/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 15:50:23 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/30 17:41:55 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			p;
	unsigned char	*st;
	unsigned char	*s;

	if (len == 0 || dest == src)
		return (dest);
	st = (unsigned char *)dest;
	s = (unsigned char *)src;
	p = 0;
	if (s > st)
	{
		while (p < len)
		{
			st[p] = s[p];
			p++;
		}
	}
	else
	{
		while (len--)
			st[len] = s[len];
	}
	return (dest);
}
