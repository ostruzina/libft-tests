/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 21:49:02 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 21:49:55 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strchr(void)
{
	t_test_case	cases[] = {
		{"find char in middle", "hello world"},
		{"find char at start", "hello world"},
		{"find char not present", "hello world"},
		{"find null terminator", "hello world"}
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
	printf("--- ft_strchr ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			ret_lib = strchr(cases[i].input, 'w');
			ret_ft = ft_strchr(cases[i].input, 'w');
		}
		else if (i == 1)
		{
			ret_lib = strchr(cases[i].input, 'h');
			ret_ft = ft_strchr(cases[i].input, 'h');
		}
		else if (i == 2)
		{
			ret_lib = strchr(cases[i].input, 'z');
			ret_ft = ft_strchr(cases[i].input, 'z');
		}
		else if (i == 3)
		{
			// Search for the null-terminator '\0'
			ret_lib = strchr(cases[i].input, '\0');
			ret_ft = ft_strchr(cases[i].input, '\0');
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
