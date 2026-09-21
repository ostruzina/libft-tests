#include "tests.h"

void	test_ft_strdup(void)
{
	t_test_case	cases[] = {
		{"duplicate normal string", "hello world"},
		{"duplicate empty string", ""},
		{"duplicate string with special chars", "42 Prague!\n\t\0"}
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
	printf("--- ft_strdup ---\n");
	while (i < test_count)
	{
		ret_lib = strdup(cases[i].input);
		ret_ft = ft_strdup(cases[i].input);

		if (ret_lib != NULL && ret_ft != NULL
			&& strcmp(ret_lib, ret_ft) == 0
			&& ret_lib != ret_ft) // Ensures distinct memory addresses
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s\n", cases[i].label);
			fail_count++;
		}

		// ASan clean-up
		free(ret_lib);
		free(ret_ft);
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}