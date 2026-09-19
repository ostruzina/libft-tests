/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:53:38 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/16 18:21:36 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_bzero(void)
{
	t_test_case	cases[] = {
		{"fill buffer with 0", NULL},
		{"zero length", NULL},
		{"fill part of buffer", NULL}
	};
	size_t		test_count;
	size_t		pass_count;
	size_t		fail_count;
	size_t		i;
	char		buf1[10];
	char		buf2[10];

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_bzero ---\n");
	while (i < test_count)
	{
		memset(buf1, 'Z', sizeof(buf1));
		memset(buf2, 'Z', sizeof(buf2));
		if (i == 0)
		{
			bzero(buf1, sizeof(buf1));
			ft_bzero(buf2, sizeof(buf2));
		}
		else if (i == 1)
		{
			bzero(buf1, (0));
			ft_bzero(buf2, (0));
		}
		else if (i == 2)
		{
			bzero(buf1, (5));
			ft_bzero(buf2, (5));
		}
		if (memcmp(buf1, buf2, sizeof(buf1)) == 0)
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s\n", cases[i].label);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
