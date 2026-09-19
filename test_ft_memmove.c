/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verosvec <verosvec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 18:43:34 by verosvec          #+#    #+#             */
/*   Updated: 2026/09/18 18:44:28 by verosvec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_ft_memmove(void)
{
	t_test_case	cases[] = {
		{"non-overlapping copy", NULL},
		{"zero length copy", NULL},
		{"overlap: dest < src (front to back)", NULL},
		{"overlap: dest > src (back to front)", NULL}
	};
	size_t	test_count;
	size_t	pass_count;
	size_t	fail_count;
	size_t	i;
	char	buf1[20];
	char	buf2[20];
	void	*ret_lib;
	void	*ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_memmove ---\n");
	while (i < test_count)
	{
		memset(buf1, 'Z', sizeof(buf1));
		memset(buf2, 'Z', sizeof(buf2));
		if (i == 0)
		{
			// Non-overlapping copy
			ret_lib = memmove(buf1, "HelloWorld!", 11);
			ret_ft = ft_memmove(buf2, "HelloWorld!", 11);
		}
		else if (i == 1)
		{
			// Zero byte copy
			ret_lib = memmove(buf1, "HelloWorld!", 0);
			ret_ft = ft_memmove(buf2, "HelloWorld!", 0);
		}
		else if (i == 2)
		{
			// Overlap dest < src: copy from offset 4 to offset 0
			strcpy(buf1, "abcdefghijklm");
			strcpy(buf2, "abcdefghijklm");
			ret_lib = memmove(buf1, buf1 + 4, 8);
			ret_ft = ft_memmove(buf2, buf2 + 4, 8);
		}
		else if (i == 3)
		{
			// Overlap dest > src: copy from offset 0 to offset 4
			strcpy(buf1, "abcdefghijklm");
			strcpy(buf2, "abcdefghijklm");
			ret_lib = memmove(buf1 + 4, buf1, 8);
			ret_ft = ft_memmove(buf2 + 4, buf2, 8);
		}

		// Verify both buffer content and return pointer match
		if (memcmp(buf1, buf2, sizeof(buf1)) == 0 &&
			(ret_ft - (void *)buf2) == (ret_lib - (void *)buf1))
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