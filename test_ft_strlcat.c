#include "tests.h"

# define BUF_CAP 64

typedef struct s_strlcat_case
{
	char	*label;
	char	*dst_init;
	char	*src;
	size_t	size;
}	t_strlcat_case;

void	test_ft_strlcat(void)
{
	t_strlcat_case	cases[] = {
		{"normal, room to spare", "ab", "cd", 20},
		{"ordinary truncation", "ab", "hello", 4},
		{"size == 0", "hello", "xy", 0},
		{"dst already >= size (pathological)", "abcdefgh", "XY", 3},
		{"empty dst", "", "hi", 10},
		{"empty src", "ab", "", 10},
		{"exact fit (no room left after concat)", "abc", "d", 4},
	};
	size_t			test_count;
	size_t			pass_count;
	size_t			fail_count;
	size_t			i;
	char			dst_ref[BUF_CAP];
	char			dst_ft[BUF_CAP];
	size_t			ret_ref;
	size_t			ret_ft;

	test_count = sizeof(cases) / sizeof(cases[0]);
	pass_count = 0;
	fail_count = 0;
	i = 0;
	printf("--- ft_strlcat ---\n");
	while (i < test_count)
	{
		ft_strlcpy(dst_ref, cases[i].dst_init, BUF_CAP);
		ft_strlcpy(dst_ft, cases[i].dst_init, BUF_CAP);
		ret_ref = reference_strlcat(dst_ref, cases[i].src, cases[i].size);
		ret_ft = ft_strlcat(dst_ft, cases[i].src, cases[i].size);
		if (ret_ref == ret_ft && strcmp(dst_ref, dst_ft) == 0)
		{
			printf("PASS: %s\n", cases[i].label);
			pass_count++;
		}
		else
		{
			printf("FAIL: %s (expected ret %zu got %zu, expected dst \"%s\" got \"%s\")\n",
				cases[i].label, ret_ref, ret_ft, dst_ref, dst_ft);
			fail_count++;
		}
		i++;
	}
	printf("Total tests: %zu\n", test_count);
	printf("Passed: %zu\n", pass_count);
	printf("Failed: %zu\n", fail_count);
}
