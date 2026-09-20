#include "tests.h"

void	test_ft_atoi(void)
{
	t_test_case	cases[] = {
		{"simple positive", "42"},
		{"simple negative", "-42"},
		{"leading spaces and tab", "   \t\n\r 123"},
		{"explicit plus sign", "+789"},
		{"trailing non-digit characters", "42hello123"},
		{"multiple signs (should return 0)", "--42"},
		{"zero value", "0"},
		{"non-digit start", "hello 42"},
		{"INT_MIN", "-2147483648"},
		{"INT_MAX", "2147483647"}
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
	printf("--- ft_atoi ---\n");
	while (i < test_count)
	{
		res_lib = atoi(cases[i].input);
		res_ft = ft_atoi(cases[i].input);

		if (res_lib == res_ft)
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