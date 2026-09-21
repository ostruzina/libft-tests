#include "tests.h"

void	test_ft_substr(void)
{
	t_test_case	cases[] = {
		{"normal substring in middle", NULL},
		{"start out of bounds", NULL},
		{"len longer than remaining string", NULL},
		{"len is zero", NULL}
	};
	size_t	test_count;
	size_t	pass_count;
	size_t	fail_count;
	size_t	i;
	char	*ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_substr ---\n");
	while (i < test_count)
	{
		if (i == 0)
			ret_ft = ft_substr("hello world", 6, 5);
		else if (i == 1)
			ret_ft = ft_substr("hello", 10, 3);
		else if (i == 2)
			ret_ft = ft_substr("hello", 2, 20);
		else if (i == 3)
			ret_ft = ft_substr("hello", 1, 0);

		if (i == 0 && ret_ft && strcmp(ret_ft, "world") == 0)
			pass_count++;
		else if (i == 1 && ret_ft && strcmp(ret_ft, "") == 0)
			pass_count++;
		else if (i == 2 && ret_ft && strcmp(ret_ft, "llo") == 0)
			pass_count++;
		else if (i == 3 && ret_ft && strcmp(ret_ft, "") == 0)
			pass_count++;
		else
		{
			printf("FAIL: %s (got \"%s\")\n", cases[i].label, ret_ft ? ret_ft : "NULL");
			fail_count++;
			free(ret_ft);
			i++;
			continue;
		}
		printf("PASS: %s\n", cases[i].label);
		free(ret_ft);
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
