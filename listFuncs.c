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

	if (head == NULL)
		return (NULL);
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->prev = NULL;
	newNode->n = n;
	newNode->next = *head;
	if (*head != NULL)
		(**head).prev = newNode;
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

/**
 * popNode - Pops the first node and returns it's value
 * @head: Start of the linked list
 *
 * Return: Value of the node
 */
int popNode(stack_t **head)
{
	int data;
	stack_t *nodePointer;

	if (*head == NULL)
		return (-1);
	nodePointer = *head;
	*head = nodePointer->next;
	data = nodePointer->n;
	free(nodePointer);
	return (data);
}

/**
 * printList - Prints out all the values of the list
 * @head: Start of the linked list
 * @line: Line number the opcode is on
 *
 * Return: void
 */
void printList(stack_t **head, unsigned int line)
{
	stack_t *nodePoint;

	if (!line)
		return;
	nodePoint = *head;
	while (nodePoint != NULL)
	{
		printf("%i\n", nodePoint->n);
		nodePoint = nodePoint->next;
	}
}

/**
 * printTop - Prints the top value of the stack
 * @head: Start of the linked list
 * @line: Line Number opcode is on
 *
 * Return: void
 */
void printTop(stack_t **head, unsigned int line)
{
	if (!line)
		return;
	printf("%i\n", (*head)->n);
}
