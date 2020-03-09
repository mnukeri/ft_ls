/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:35:57 by mnukeri           #+#    #+#             */
/*   Updated: 2019/06/16 14:28:13 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *space;

	space = (unsigned char *)malloc(sizeof(char) * size);
	if (space == NULL)
		return (NULL);
	ft_memset(space, 0, size);
	return (space);
}
