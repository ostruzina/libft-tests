/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 19:50:00 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/20 21:03:13 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strnstr(void)
{
	t_test_case	cases[] = {
		{"needle in middle within len", NULL},
		{"needle in middle outside len", NULL},
		{"empty needle", NULL},
		{"needle not found", NULL},
		{"len shorter than needle length", NULL},
		{"partial match cut off by len", NULL},
		{"search past null terminator", NULL},
		{"len is zero", NULL},
		{"backwards-sensitive underflow", NULL}
	};
	size_t	test_count;
	size_t	pass_count;
	size_t	fail_count;
	size_t	i;
	char	*ret_lib;
	char	*ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_strnstr ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			ret_lib = bsd_strnstr("Foo Bar Baz", "Bar", 8);
			ret_ft = ft_strnstr("Foo Bar Baz", "Bar", 8);
		}
		else if (i == 1)
		{
			// "Bar" is at index 4-6, but len = 4 cuts it off
			ret_lib = bsd_strnstr("Foo Bar Baz", "Bar", 4);
			ret_ft = ft_strnstr("Foo Bar Baz", "Bar", 4);
		}
		else if (i == 2)
		{
			// Empty needle should return haystack
			ret_lib = bsd_strnstr("Foo Bar Baz", "", 10);
			ret_ft = ft_strnstr("Foo Bar Baz", "", 10);
		}
		else if (i == 3)
		{
			ret_lib = bsd_strnstr("Foo Bar Baz", "42", 11);
			ret_ft = ft_strnstr("Foo Bar Baz", "42", 11);
		}
		else if (i == 4)
		{
			ret_lib = bsd_strnstr("hello", "hello world", 5);
			ret_ft = ft_strnstr("hello", "hello world", 5);
		}
		else if (i == 5)
		{
			// Match starts at index 3 ("A"), but len=5 only allows reading index 0..4
			ret_lib = bsd_strnstr("abcAAAA", "AAAA", 5);
			ret_ft = ft_strnstr("abcAAAA", "AAAA", 5);
		}
		else if (i == 6)
		{
			// Search bounds past '\0' byte
			ret_lib = bsd_strnstr("hello\0world", "world", 11);
			ret_ft = ft_strnstr("hello\0world", "world", 11);
		}
		else if (i == 7)
		{
			// Edge case A: Zero length search
			ret_lib = bsd_strnstr("hello world", "hello", 0);
			ret_ft = ft_strnstr("hello world", "hello", 0);
		}
		else if (i == 8)
		{
			// Edge case B: Full match within len using backwards-sensitive underflow
			ret_lib = bsd_strnstr("hello world", "hello", 5);
			ret_ft = ft_strnstr("hello world", "hello", 5);
		}
		if (ret_lib == ret_ft)
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected %p, got %p)\n",
				cases[i].label, (void *)ret_lib, (void *)ret_ft);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}