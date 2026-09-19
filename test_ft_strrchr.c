/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 22:06:43 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 22:06:47 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strrchr(void)
{
	t_test_case	cases[] = {
		{"find last occurrence of repeated char", "hello world"},
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
	printf("--- ft_strrchr ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			ret_lib = strrchr(cases[i].input, 'l');
			ret_ft = ft_strrchr(cases[i].input, 'l');
		}
		else if (i == 1)
		{
			ret_lib = strrchr(cases[i].input, 'h');
			ret_ft = ft_strrchr(cases[i].input, 'h');
		}
		else if (i == 2)
		{
			ret_lib = strrchr(cases[i].input, 'z');
			ret_ft = ft_strrchr(cases[i].input, 'z');
		}
		else if (i == 3)
		{
			ret_lib = strrchr(cases[i].input, '\0');
			ret_ft = ft_strrchr(cases[i].input, '\0');
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
