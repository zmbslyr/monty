#include "monty.h"

/**
 * opFc - Checks the opcode and runs a fuction
 * @o: Opcode
 * @h: Head of the stack
 * @f: File for closing purposes
 *
 * Return: Function Pointer
 */
void (*opFc(stack_t **h, FILE **f))(stack_t **s, unsigned int l)
{
	instruction_t funcs[] = {
		{"pall", printList},
		{"pint", printTop},
		{NULL, NULL}
	};
	int index = 0;

	while (funcs[index].opcode != NULL)
	{
		if (strncmp(funcs[index].opcode, globals.opcode, 3) == 0)
			return (funcs[index].f);
		fprintf(stderr, "L%d: unknown instruction %s\n", globals.line, globals.opcode);
		freeList(h);
		fclose(*f);
		exit(EXIT_FAILURE);
		index++;
	}
	return (NULL);
}
