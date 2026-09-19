/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 20:12:50 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 20:14:02 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_memcmp(void)
{
	t_test_case	cases[] = {
		{"identical buffers", NULL},
		{"s1 < s2 (differs at index 3)", NULL},
		{"s1 > s2 (differs at index 3)", NULL},
		{"zero length comparison", NULL},
		{"differs past null byte", NULL}
	};
	size_t	test_count;
	size_t	pass_count;
	size_t	fail_count;
	size_t	i;
	int		res_lib;
	int		res_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_memcmp ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			res_lib = memcmp("abcdef", "abcdef", 6);
			res_ft = ft_memcmp("abcdef", "abcdef", 6);
		}
		else if (i == 1)
		{
			res_lib = memcmp("abcAef", "abcdef", 6);
			res_ft = ft_memcmp("abcAef", "abcdef", 6);
		}
		else if (i == 2)
		{
			res_lib = memcmp("abcdef", "abcAef", 6);
			res_ft = ft_memcmp("abcdef", "abcAef", 6);
		}
		else if (i == 3)
		{
			res_lib = memcmp("abcdef", "abcXYZ", 0);
			res_ft = ft_memcmp("abcdef", "abcXYZ", 0);
		}
		else if (i == 4)
		{
			// Binary memory check past '\0'
			res_lib = memcmp("abc\0def", "abc\0dEf", 7);
			res_ft = ft_memcmp("abc\0def", "abc\0dEf", 7);
		}

		// Normalize signs since standard library only
		// guarantees sign match (+/-/0), value may differ
		if ((res_lib == 0 && res_ft == 0) ||
			(res_lib > 0 && res_ft > 0) ||
			(res_lib < 0 && res_ft < 0))
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected %d, got %d)\n",
				cases[i].label, res_lib, res_ft);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
