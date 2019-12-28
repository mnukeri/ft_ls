/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 16:48:49 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/16 17:26:34 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	p;
	unsigned int	k;
	unsigned int	m;
	char			*new;

	if (s == NULL || f == NULL)
		return (NULL);
	m = ft_strlen(s) + 1;
	new = (char*)malloc(sizeof(char) * m);
	if (new == NULL)
		return (NULL);
	p = 0;
	k = 0;
	while (s[p] != '\0')
	{
		new[k] = f(p, *(char*)&s[p]);
		p++;
		k++;
	}
	new[k] = '\0';
	return (new);
}
