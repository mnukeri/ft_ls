/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:53:22 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/29 14:44:13 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		p;
	int		len;
	char	*str;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	p = 0;
	while (p < len)
	{
		str[p] = s1[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}
