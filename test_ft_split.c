#include "tests.h"

void	test_ft_split(void)
{
	char	**res;
	size_t	i;

	printf("--- ft_split ---\n");

	// Test 1: Standard string
	res = ft_split("  hello   world  42  ", ' ');
	if (res && res[0] && strcmp(res[0], "hello") == 0
		&& res[1] && strcmp(res[1], "world") == 0
		&& res[2] && strcmp(res[2], "42") == 0
		&& res[3] == NULL)
		printf("PASS: Standard split with extra spaces\n");
	else
		printf("FAIL: Standard split\n");
	i = 0;
	while (res && res[i])
		free(res[i++]);
	free(res);

	// Test 2: No delimiters
	res = ft_split("helloworld", ' ');
	if (res && res[0] && strcmp(res[0], "helloworld") == 0 && res[1] == NULL)
		printf("PASS: No delimiter found\n");
	else
		printf("FAIL: No delimiter found\n");
	i = 0;
	while (res && res[i])
		free(res[i++]);
	free(res);

	// Test 3: Empty string
	res = ft_split("", ' ');
	if (res && res[0] == NULL)
		printf("PASS: Empty string split\n");
	else
		printf("FAIL: Empty string split\n");
	free(res);
}
