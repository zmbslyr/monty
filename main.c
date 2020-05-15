#include "monty.h"

/**
 * main - Entry point
 * @argc: Number of arguments given to main
 * @argv: Arguments stored in string format
 *
 * Return: Always 0 
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL, str[10];
	ssize_t read = 0;
	size_t bufSize = 0;
	int n = 0, scan;
	stack_t *stack = NULL;

	if (argc != 2)
		usageErr();
	globals.file = argv[1];
	fp = fopen(globals.file, "r");
	if (fp == NULL)
		fileErr();
	globals.line = 0;
	while ((read = getline(&line, &bufSize, fp)) != -1)
	{
		globals.line++;
		scan = sscanf(line, "%s %d", str, &n);
		if (scan > 2)
		{
			free(line);
			usageErr();
		}
		globals.opcode = str;
		free(line);
		line = NULL;
		if (strcmp(str, "push") == 0)
			addNode(&stack, n);
		else if (strcmp(str, "pop") == 0)
			popNode(&stack);
		else if (strcmp(globals.opcode, "nop") == 0)
			nopFunc(&stack, globals.line);
		else
			opFc(&stack, &fp)(&stack, globals.line);
	}
	free(line);
	freeList(&stack);
	fclose(fp);
	return (0);
}
