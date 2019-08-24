/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:12:42 by mnukeri           #+#    #+#             */
/*   Updated: 2019/08/24 16:18:14 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_sorter(char **s);
int		ft_array_swap(chae *s1, char *s2);
int		ft_content_display(char **s);
int		ft_dir_count(char **dir);
char	**ft_dir_copy(char **dir, int k);

#endif
