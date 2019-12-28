/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:33:37 by mnukeri           #+#    #+#             */
/*   Updated: 2019/05/24 16:05:35 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	p;
	size_t	k;
	char	*found;

	p = 0;
	if (needle[0] == '\0')
		return ((char *)str);
	while ((str[p] != '\0') && n > p)
	{
		k = 0;
		if ((needle[k] == str[p]))
		{
			found = (char *)&str[p];
			while ((needle[k] == str[p]) && p < n)
			{
				if (needle[k + 1] == '\0')
					return (found);
				k++;
				p++;
			}
		}
		else
			p++;
	}
	return (NULL);
}
