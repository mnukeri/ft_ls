/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:41:29 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/28 16:51:57 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	p;
	size_t	k;
	char	*new;

	if (str == NULL)
		return (NULL);
	p = 0;
	while (str[p] != '\0' && p < start)
		p++;
	if (!(new = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	k = 0;
	while (str[p] != '\0' && k < len)
		new[k++] = str[p++];
	new[k] = '\0';
	return (new);
}
