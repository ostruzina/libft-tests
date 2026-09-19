#include "tests.h"

# define DST_CAP 32

void	test_ft_strlcpy(void)
{
	t_test_case	cases[] = {
		{"room to spare, no truncation", "hello"},
		{"exact fit (size == strlen + 1)", "hello"},
		{"truncation", "hello"},
		{"size == 1, only room for terminator", "hello"},
		{"size == 0, dst untouched", "hello"},
		{"empty src", ""},
		{"src longer than claimed dst size", "this is a long string"},
	};
	size_t		call_size[] = {10, 6, 3, 1, 0, 10, 4};
	size_t		test_count;
	size_t		pass_count;
	size_t		fail_count;
	size_t		i;
	char		dst_ref[DST_CAP];
	char		dst_ft[DST_CAP];
	size_t		ret_ref;
	size_t		ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_strlcpy ---\n");
	while (i < test_count)
	{
		memset(dst_ref, 'Z', DST_CAP);
		memset(dst_ft, 'Z', DST_CAP);
		ret_ref = reference_strlcpy(dst_ref, cases[i].input, call_size[i]);
		ret_ft = ft_strlcpy(dst_ft, cases[i].input, call_size[i]);
		if (ret_ref == ret_ft && memcmp(dst_ref, dst_ft, DST_CAP) == 0)
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected ret %zu got %zu)\n",
				cases[i].label, ret_ref, ret_ft);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
