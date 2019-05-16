#include "monty.h"

/**
 * usageErr - Error for if the program isn't called correctly
 *
 * Return: void
 */
void usageErr(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * fileErr - Prints an error if file cannot be opened
 *
 * Return: void
 */
void fileErr(void)
{
	fprintf(stderr, "Error: Can't open file %s\n", globals.file);
	exit(EXIT_FAILURE);
}