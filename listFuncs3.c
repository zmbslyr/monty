#include "monty.h"

/**
 * mulFunc - Multiplies the top two elements
 * @stack: Start of the stack
 * @line: Line number
 *
 * Return: void 
 */
void mulFunc(stack_t **stack, unsigned int line)
{
	int a, b;

	if (!(stack)[1])
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = popNode(stack);
	b = popNode(stack);
	addNode(stack, b * a);
}

/**
 * modFunc - Mods the second top element by the top element
 * @stack: Start of the stack
 * @line: Line number
 *
 * Return: void
 */
void modFunc(stack_t **stack, unsigned int line)
{
	int a, b;

	if (!(stack)[1])
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = popNode(stack);
	b = popNode(stack);
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	addNode(stack, b % a);
}
