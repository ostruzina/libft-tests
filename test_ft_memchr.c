/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 19:23:24 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 19:24:01 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_memchr(void)
{
	t_test_case	cases[] = {
		{"find char in middle", "hello world"},
		{"find char at start", "hello world"},
		{"find char not present", "hello world"},
		{"zero length search", "hello world"},
		{"find char past null byte", "hello\0world"}
	};
	size_t	test_count;
	size_t	pass_count;
	size_t	fail_count;
	size_t	i;
	void	*ret_lib;
	void	*ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_memchr ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			ret_lib = memchr(cases[i].input, 'w', 11);
			ret_ft = ft_memchr(cases[i].input, 'w', 11);
		}
		else if (i == 1)
		{
			ret_lib = memchr(cases[i].input, 'h', 11);
			ret_ft = ft_memchr(cases[i].input, 'h', 11);
		}
		else if (i == 2)
		{
			ret_lib = memchr(cases[i].input, 'x', 11);
			ret_ft = ft_memchr(cases[i].input, 'x', 11);
		}
		else if (i == 3)
		{
			ret_lib = memchr(cases[i].input, 'w', 0);
			ret_ft = ft_memchr(cases[i].input, 'w', 0);
		}
		else if (i == 4)
		{
			// Memory search should not stop at '\0'
			ret_lib = memchr(cases[i].input, 'w', 11);
			ret_ft = ft_memchr(cases[i].input, 'w', 11);
		}

		if (ret_lib == ret_ft)
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected %p, got %p)\n",
				cases[i].label, ret_lib, ret_ft);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
