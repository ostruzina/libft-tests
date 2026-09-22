/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:39:11 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/22 18:18:57 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include "../libft.h"

typedef struct s_test_case
{
	char	*label;
	char	*input;
}	t_test_case;

size_t	reference_strlcpy(char *dst, const char *src, size_t siz);
size_t	reference_strlcat(char *dst, const char *src, size_t dsize);
char	*bsd_strnstr(const char *s, const char *find, size_t slen);
void	test_ft_strlen(void);
void	test_ft_memset(void);
void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isalnum(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);
void	test_ft_toupper(void);
void	test_ft_tolower(void);
void	test_ft_memmove(void);
void	test_ft_memchr(void);
void	test_ft_memcmp(void);
void	test_ft_strchr(void);
void	test_ft_strrchr(void);
void	test_ft_strlcpy(void);
void	test_ft_strlcat(void);
void	test_ft_strncmp(void);
void	test_ft_strnstr(void);
void	test_ft_atoi(void);
void	test_ft_calloc(void);
void	test_ft_strdup(void);
void	test_ft_substr(void);
void	test_ft_strjoin(void);
void	test_ft_put_fd(void);
void	test_ft_strm_iter(void);
void	test_ft_strtrim(void);

#endif
