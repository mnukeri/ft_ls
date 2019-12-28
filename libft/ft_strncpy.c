/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:32:16 by mnukeri           #+#    #+#             */
/*   Updated: 2019/07/08 17:30:11 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t p;

	if (len == 0)
		return (dest);
	ft_bzero(dest, len);
	p = 0;
	while (src[p] && p < len)
	{
		dest[p] = src[p];
		p++;
	}
	return (dest);
}
