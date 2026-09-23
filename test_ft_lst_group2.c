#include "tests.h"

void	test_ft_lst_group2(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	printf("--- Group 2: Traversal & Adding Back ---\n");
	head = NULL;

	// 1. Test empty list behavior
	if (ft_lstsize(head) == 0 && ft_lstlast(head) == NULL)
		printf("PASS: Empty list queries\n");
	else
		printf("FAIL: Empty list queries\n");

	// 2. Add to back on empty list
	node1 = ft_lstnew("One");
	ft_lstadd_back(&head, node1);
	if (head == node1 && ft_lstsize(head) == 1 && ft_lstlast(head) == node1)
		printf("PASS: ft_lstadd_back on empty list\n");
	else
		printf("FAIL: ft_lstadd_back on empty list\n");

	// 3. Add more nodes to back
	node2 = ft_lstnew("Two");
	node3 = ft_lstnew("Three");
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);

	if (ft_lstsize(head) == 3)
		printf("PASS: ft_lstsize equals 3\n");
	else
		printf("FAIL: ft_lstsize incorrect\n");

	if (ft_lstlast(head) == node3)
		printf("PASS: ft_lstlast points to node3\n");
	else
		printf("FAIL: ft_lstlast incorrect\n");

	free(node1);
	free(node2);
	free(node3);
}