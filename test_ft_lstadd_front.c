#include "tests.h"

void	test_ft_lstadd_front(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	printf("--- ft_lstadd_front ---\n");
	head = NULL;
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");

	ft_lstadd_front(&head, node1);
	ft_lstadd_front(&head, node2);

	if (head == node2 && head->next == node1 && head->next->next == NULL)
		printf("PASS: ft_lstadd_front links properly\n");
	else
		printf("FAIL: ft_lstadd_front failed to attach nodes\n");

	free(node1);
	free(node2);
}
