/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:34:35 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/28 16:39:31 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int		p;
	char	*new;
	int		m;
	int		k;

	if (s == NULL)
		return (NULL);
	p = 0;
	while (s[p] == '\t' || s[p] == ' ' || s[p] == '\n')
		p++;
	m = ft_strlen(s) - 1;
	if (m > p)
		while (s[m] == ' ' || s[m] == '\t' || s[m] == '\n')
			m--;
	k = m + 1 - p;
	if (!(new = (char*)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	m = 0;
	while (m < k && s[p])
		new[m++] = s[p++];
	new[m] = '\0';
	return (new);
}
