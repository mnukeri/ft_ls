/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_holder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:52:54 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/01 18:08:27 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**input_holder(char **input)
{
	char	**i_h;
	char	*s;
	int		p;
	int		k;

	if (input == NULL)
		return (NULL);
	p = 0;
	while (input[p])
		k += ft_strlen(input[p++]);
	if (!(s = ft_memalloc(k + 1)))
	{
		ft_putendl("Could not allocate string memory so that we can chop it up via strsplit, harde ntwana;");
		return (0);
	}
	p = 0;
	while (input[p])
	{
		ft_strcat(s, input[p++]);
		ft_strcat(s, " ");
	}
	if (!(i_h = ft_strsplit(s, ' ')))
	{
		ft_putendl("Could not split the 'input string', harde ntwana;");
		return (0);
	}
	return (i_h);
}
