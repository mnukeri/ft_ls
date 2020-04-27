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

int		flag_checker(char **input);
char	*path_checker(char **input);
int		ls_process(char **dir, int k);
int     ls_process_R(char **dir);
char    **ft_diff_flag(char **dir, int k);
int     ft_dir_check(const char *st);
int		ft_array_swap(char *s1, char *s2);
int		ft_dir_count(char **dir);
int     ft_dir_count_R(char **dir);
int     ft_dir_count_hid(char **dir);
char	**ft_dir_copy(char **dir, int k);
char    *ft_pr_perm(unsigned int perms, int direc);
int     ft_dir_strlen(char **dir);
int		ft_sorter(char **s, char **dir, int k);
int     ft_sorter_l(char **s, char **dir);
int     ft_sorter_t(char **s, char **dir);
int		ft_content_display(char **s, char **dir, int k);
int     ft_pDirent_reader(DIR *pDir);
//int     ft_flag_L(char **dir);

#endif
