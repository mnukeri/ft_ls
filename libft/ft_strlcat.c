/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:18:17 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/09 13:24:44 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t		p;
	size_t		len;
	char		*des;
	const char	*sr;

	des = dest;
	sr = src;
	p = destsize;
	while (p-- != 0 && *des != '\0')
		des++;
	len = des - dest;
	p = destsize - len;
	if (p == 0)
		return (len + ft_strlen(sr));
	while (*sr)
	{
		if (p > 1)
		{
			*des++ = *sr;
			p--;
		}
		sr++;
	}
	*des = '\0';
	return (len + (sr - src));
}
