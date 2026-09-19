/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 19:48:40 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/17 21:05:02 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_memcpy(void)
{
	t_test_case	cases[] = {
		{"fill with 'A'", "AAAAAAAAAA"},
		{"fill with 0", "0000000000"},
		{"fill 0 bytes", "0000000000"},
	};
	size_t		test_count;
	size_t		pass_count;
	size_t		fail_count;
	size_t		i;
	char		dest_buf1[10];
	char		dest_buf2[10];

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_memcpy ---\n");
	while (i < test_count)
	{
		memset(dest_buf1, 'Z', sizeof(dest_buf1));
		memset(dest_buf2, 'Z', sizeof(dest_buf2));
		if (i == 0)
		{
			memcpy(dest_buf1, cases[i].input, sizeof(dest_buf1));
			ft_memcpy(dest_buf2, cases[i].input, sizeof(dest_buf2));
		}
		else if (i == 1)
		{
			memcpy(dest_buf1, cases[i].input, sizeof(dest_buf1));
			ft_memcpy(dest_buf2, cases[i].input, sizeof(dest_buf2));
		}
		else if (i == 2)
		{
			memcpy(dest_buf1, cases[i].input, (0));
			ft_memcpy(dest_buf2, cases[i].input, (0));
		}
		if (memcmp(dest_buf1, dest_buf2, sizeof(dest_buf1)) == 0)
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
