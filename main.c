#include "monty.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	stack_t *head, *nodePointer;
	int n = 45;

	head = NULL;
	while (n > 0)
	{
		addNode(&head, n);
		n--;
	}
	nodePointer = head;
	while (nodePointer != NULL)
	{
		printf("%d\n", nodePointer->n);
		nodePointer = nodePointer->next;
	}
	freeList(&head);
	return (0);
}
