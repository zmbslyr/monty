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
		{"swap", swapFunc},
		{"nop", nopFunc},
		{"add", addFunc},
		{"sub", subFunc},
		{"div", divFunc},
		{"mul", mulFunc},
		{"mod", modFunc},
		{NULL, NULL}
	};
	int index = 0;

	while (funcs[index].opcode != NULL)
	{
		if (strcmp(funcs[index].opcode, globals.opcode) == 0)
			return (funcs[index].f);
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", globals.line, globals.opcode);
	freeList(h);
	fclose(*f);
	exit(EXIT_FAILURE);
		
	return (NULL);
}
