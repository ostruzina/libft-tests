#include "tests.h"

void	test_ft_strjoin(void)
{
	t_test_case	cases[] = {
		{"join two words", NULL},
		{"join with empty string", NULL},
		{"join two empty strings", NULL}
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
	printf("--- ft_strjoin ---\n");
	while (i < test_count)
	{
		if (i == 0)
			ret_ft = ft_strjoin("hello ", "world");
		else if (i == 1)
			ret_ft = ft_strjoin("hello", "");
		else if (i == 2)
			ret_ft = ft_strjoin("", "");

		if (i == 0 && ret_ft && strcmp(ret_ft, "hello world") == 0)
			pass_count++;
		else if (i == 1 && ret_ft && strcmp(ret_ft, "hello") == 0)
			pass_count++;
		else if (i == 2 && ret_ft && strcmp(ret_ft, "") == 0)
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