/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 20:29:48 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/15 19:16:05 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_strlen(void)
{
	int			i;
	size_t		res_ft;
	size_t		res_lib;
	int			pass_count;
	int			fail_count;
	int			test_count;
	char		*long_string;
	t_test_case	test_cases[] = {
		{"One word", "Hello"},
		{"Empty string", ""},
		{"Single space", " "},
		{"Special characters ~/-;", "~/-;"},
		{"Two words", "hello hello"},
		{"Tab character", "\t"},
		{"Very long string", NULL},
	};

	i = 0;
	pass_count = 0;
	fail_count = 0;
	test_count = sizeof(test_cases) / sizeof(test_cases[0]);
	long_string = malloc(10001);
	if (long_string == NULL)
		return ;
	memset(long_string, 'x', 10000);
	long_string[10000] = '\0';
	test_cases[6].input = long_string;

	while (i < test_count)
	{
		res_ft = ft_strlen(test_cases[i].input);
		res_lib = strlen(test_cases[i].input);
		printf("Test: %s\n", test_cases[i].label);
		if (res_ft == res_lib)
		{
			printf("  PASS\n");
			pass_count++;
		}
		else
		{
			printf("  FAIL\n");
			printf("    Result of ft_strlen: %zu\n", res_ft);
			printf("    Result of libc function: %zu\n", res_lib);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %d\n", test_count);
	printf("Passed: %d\n", pass_count);
	printf("Failed: %d\n", fail_count);
	free(long_string);
}
