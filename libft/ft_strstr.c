/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:55:42 by mnukeri           #+#    #+#             */
/*   Updated: 2019/05/24 16:23:39 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	int p;
	int k;

	p = 0;
	if (needle[0] == '\0')
		return ((char *)str);
	while (str[p] != '\0')
	{
		k = 0;
		while (needle[k] == str[p + k])
		{
			if (needle[k + 1] == '\0')
			{
				return ((char *)&str[p]);
			}
			k++;
		}
		p++;
	}
	return (NULL);
}
