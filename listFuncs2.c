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
