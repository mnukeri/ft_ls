/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:25:19 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/30 16:48:32 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			p;
	unsigned char	*st;
	unsigned char	*str;

	st = (unsigned char *)dest;
	str = (unsigned char *)src;
	p = 0;
	while (p < n)
	{
		st[p] = str[p];
		if (str[p] == (unsigned char)c)
			return (dest + p);
		p++;
	}
	return (0);
}
