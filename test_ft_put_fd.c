#include "tests.h"

void	test_ft_put_fd(void)
{
	printf("--- ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd ---\n");

	// Outputting directly to STDOUT (fd 1) to visually verify format
	printf("[putchar] Expected 'A': ");
	ft_putchar_fd('A', 1);
	printf("\n");

	printf("[putstr]  Expected 'Hello': ");
	ft_putstr_fd("Hello", 1);
	printf("\n");

	printf("[putendl] Expected 'World' with newline:\n");
	ft_putendl_fd("World", 1);

	printf("[putnbr]  Expected '0': ");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("[putnbr]  Expected '-42': ");
	ft_putnbr_fd(-42, 1);
	printf("\n");

	printf("[putnbr]  Expected '-2147483648': ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");

	printf("PASS: fd output tests completed.\n");
}