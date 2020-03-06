/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnukeri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 16:12:42 by mnukeri           #+#    #+#             */
/*   Updated: 2019/09/12 16:15:28 by mnukeri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <time.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>

int		ft_sorter(char **s);
int     ft_sorter_l(char **s);
int     ft_sorter_t(char **s);
int		ft_array_swap(char *s1, char *s2);
char    **ft_diff_flag(char **s, int k);
int		ft_content_display(char **s, int k);
int		ft_dir_count(char **dir, int k);
char	**ft_dir_copy(char **dir, int k);
int		ls_process(char **dir, int k);
int		flag_checker(char **input);
char	*path_checker(char **input);
int     ft_dir_check(char *st);
int     ls_process_R(char **dir);
//int     ft_flag_L(char **dir);
char    *ft_pr_perm(unsigned int perms, int direc);

#endif
