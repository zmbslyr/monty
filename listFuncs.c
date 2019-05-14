#include "monty.h"

/**
 * addNode - Adds a node to the linked list
 * @head: Head Node of the linked list
 * @n: data to populate node with
 *
 * Return: Address of the new node
 */
stack_t *addNode(stack_t **head, int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->prev = NULL;
	newNode->n = n;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}

/**
 * freeList - Frees a doubly linked list
 * @head: Head node of the linked list
 *
 * Return: 0 (Success)
 */
int freeList(stack_t **head)
{
	stack_t *nodePointer;

	if (head == NULL || *head == NULL)
		return (-1);
	while (*head != NULL)
	{
		nodePointer = *head;
		*head = (*head)->next;
		free(nodePointer);
	}
	return (0);
}
