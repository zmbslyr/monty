#include "monty.h"

/**
 * nopFunc - Does nothing
 * @stack: Start of the stack
 * @line: Line Number
 *
 * Return: void 
 */
void nopFunc(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
}

/**
 * swapFunc - Swaps the top two nodes in the stack
 * @stack: Start of the stack
 * @line: Line number
 *
 * Return: void
 */
void swapFunc(stack_t **stack, unsigned int line)
{
	int swap;

	if (!(stack)[1])
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	swap = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap;

}

/**
 * addFunc - Adds the top two nodes
 * @stack: Start of the stack
 * @line: Line Number
 *
 * Return: void
 */
void addFunc(stack_t **stack, unsigned int line)
{
	int a, b;

	if (!(stack)[1])
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = popNode(stack);
	b = popNode(stack);
	addNode(stack, a + b);

}

/**
 * subFunc - Subtracts the top element from the second element
 * @stack: Start of the stack
 * @line: Line number
 *
 * Return: void
 */
void subFunc(stack_t **stack, unsigned int line)
{
	int a, b;

	if (!(stack)[1])
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	a = popNode(stack);
	b = popNode(stack);
	addNode(stack, b - a);
}

/**
 * divFunc - Divides the second top element by the top element
 * @stack: Start of the stack
 * @line: Line number
 *
 * Return: void
 */
void divFunc(stack_t **stack, unsigned int line)
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
	addNode(stack, b / a);
}
