/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:39:11 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 22:07:48 by verosvec         ###   ########.fr       */
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

#endif
