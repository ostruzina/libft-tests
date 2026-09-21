#include "tests.h"

// Callback for ft_strmapi: Shifts characters by index (c + i)
static char	map_shift_by_index(unsigned int i, char c)
{
	return (c + (char)i);
}

// Callback for ft_striteri: Converts characters to uppercase in-place
static void	iter_to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	test_ft_strm_iter(void)
{
	printf("--- ft_strmapi & ft_striteri ---\n");

	// 1. Test ft_strmapi
	char	*strmapi_res;

	strmapi_res = ft_strmapi("abcde", map_shift_by_index);
	// 'a'+0='a', 'b'+1='c', 'c'+2='e', 'd'+3='g', 'e'+4='i' -> "acegi"
	if (strmapi_res && strcmp(strmapi_res, "acegi") == 0)
		printf("PASS: ft_strmapi transformation\n");
	else
		printf("FAIL: ft_strmapi expected \"acegi\", got \"%s\"\n", strmapi_res ? strmapi_res : "NULL");
	free(strmapi_res);

	// Guard test for ft_strmapi
	if (ft_strmapi(NULL, map_shift_by_index) == NULL && ft_strmapi("test", NULL) == NULL)
		printf("PASS: ft_strmapi NULL guards\n");
	else
		printf("FAIL: ft_strmapi NULL guards failed\n");

	// 2. Test ft_striteri (Must use a char array on stack, NOT a string literal!)
	char	striteri_str[] = "hello 42";

	ft_striteri(striteri_str, iter_to_upper);
	if (strcmp(striteri_str, "HELLO 42") == 0)
		printf("PASS: ft_striteri in-place modification\n");
	else
		printf("FAIL: ft_striteri expected \"HELLO 42\", got \"%s\"\n", striteri_str);

	// Guard test for ft_striteri (Should not crash on NULL)
	ft_striteri(NULL, iter_to_upper);
	ft_striteri(striteri_str, NULL);
	printf("PASS: ft_striteri NULL guards\n");
}