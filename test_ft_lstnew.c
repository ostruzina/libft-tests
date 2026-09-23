#include "tests.h"

void	test_ft_lstnew(void)
{
	t_list	*node;
	char	*str = "Hello 42";

	printf("--- ft_lstnew ---\n");
	node = ft_lstnew(str);
	if (node && node->content == str && node->next == NULL)
		printf("PASS: ft_lstnew node creation\n");
	else
		printf("FAIL: ft_lstnew node creation\n");
	free(node); // Free only the node container, not 'str' (it's a literal!)
}
