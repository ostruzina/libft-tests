#include "tests.h"

void	test_ft_strncmp(void)
{
	t_test_case	cases[] = {
		{"equal strings within n", NULL},
		{"s1 shorter than s2", NULL},
		{"s1 longer than s2", NULL},
		{"differs before n", NULL},
		{"zero length comparison", NULL}
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
	printf("--- ft_strncmp ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			res_lib = strncmp("hello", "hello", 5);
			res_ft = ft_strncmp("hello", "hello", 5);
		}
		else if (i == 1)
		{
			res_lib = strncmp("abc", "abcdef", 6);
			res_ft = ft_strncmp("abc", "abcdef", 6);
		}
		else if (i == 2)
		{
			res_lib = strncmp("abcdef", "abc", 6);
			res_ft = ft_strncmp("abcdef", "abc", 6);
		}
		else if (i == 3)
		{
			res_lib = strncmp("hello", "helZo", 5);
			res_ft = ft_strncmp("hello", "helZo", 5);
		}
		else if (i == 4)
		{
			res_lib = strncmp("hello", "world", 0);
			res_ft = ft_strncmp("hello", "world", 0);
		}

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