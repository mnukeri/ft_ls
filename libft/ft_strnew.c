/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:40:16 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/28 21:53:32 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	p;
	char	*new;

	new = (char*)malloc((size + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	p = 0;
	while (p < size)
		new[p++] = '\0';
	new[p] = '\0';
	return (*(&new));
}
