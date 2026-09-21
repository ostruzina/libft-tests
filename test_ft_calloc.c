#include "tests.h"

void	test_ft_calloc(void)
{
	t_test_case	cases[] = {
		{"allocate int array", NULL},
		{"allocate string buffer", NULL},
		{"zero nmemb", NULL},
		{"zero size", NULL}
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
	printf("--- ft_calloc ---\n");
	while (i < test_count)
	{
		if (i == 0)
		{
			ret_lib = calloc(5, sizeof(int));
			ret_ft = ft_calloc(5, sizeof(int));
		}
		else if (i == 1)
		{
			ret_lib = calloc(10, sizeof(char));
			ret_ft = ft_calloc(10, sizeof(char));
		}
		else if (i == 2)
		{
			ret_lib = calloc(0, sizeof(int));
			ret_ft = ft_calloc(0, sizeof(int));
		}
		else if (i == 3)
		{
			ret_lib = calloc(5, 0);
			ret_ft = ft_calloc(5, 0);
		}

		// Verify non-null pointer returned
		if (ret_lib != NULL && ret_ft != NULL)
		{
			// For non-zero allocations, verify all bytes are zeroed
			if (i == 0 && memcmp(ret_lib, ret_ft, 5 * sizeof(int)) == 0)
			{
				printf("PASS: %s\n", cases[i].label);
				pass_count++;
			}
			else if (i == 1 && memcmp(ret_lib, ret_ft, 10) == 0)
			{
				printf("PASS: %s\n", cases[i].label);
				pass_count++;
			}
			else if (i >= 2)
			{
				// For zero-size, verify pointer is valid and non-NULL
				printf("PASS: %s\n", cases[i].label);
				pass_count++;
			}
			else
			{
				printf("FAIL: %s (memory contents differ)\n", cases[i].label);
				fail_count++;
			}
		}
		else
		{
			printf("FAIL: %s (returned NULL pointer)\n", cases[i].label);
			fail_count++;
		}

		// Clean up heap allocations so ASan doesn't report leaks!
		free(ret_lib);
		free(ret_ft);
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}