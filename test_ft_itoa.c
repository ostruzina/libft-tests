#include "tests.h"

// Dedicated, semantically clear struct for ft_itoa tests
typedef struct s_itoa_test
{
	const char	*label;
	int			value;
	const char	*expected;
}	t_itoa_test;

void	test_ft_itoa(void)
{
	t_itoa_test	cases[] = {
		{"zero", 0, "0"},
		{"single positive digit", 7, "7"},
		{"single negative digit", -5, "-5"},
		{"standard positive number", 12345, "12345"},
		{"standard negative number", -9876, "-9876"},
		{"INT_MAX", 2147483647, "2147483647"},
		{"INT_MIN", -2147483648, "-2147483648"}
	};
	size_t		test_count;
	size_t		pass_count;
	size_t		fail_count;
	size_t		i;
	char		*res;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_itoa ---\n");
	while (i < test_count)
	{
		res = ft_itoa(cases[i].value);
		if (res && strcmp(res, cases[i].expected) == 0)
		{
			printf("PASS: %s (%d -> \"%s\")\n", cases[i].label, cases[i].value, res);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected \"%s\", got \"%s\")\n",
				cases[i].label, cases[i].expected, res ? res : "NULL");
			fail_count++;
		}
		free(res);
		i++;
	}
	printf("Total tests: %zu | Passed: %zu | Failed: %zu\n",
		test_count, pass_count, fail_count);
}
