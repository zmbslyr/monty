#include "monty.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	stack_t *head;

	head = malloc(sizeof(stack_t));
	if (head == NULL)
		return (-1);
	head->n = 1;
	printf("%d\n", head->n);
}