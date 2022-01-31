#ifndef __MONTY__
#define __MONTY__

/* Includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* TEST Line CHange /*

/* Structs */
/**
 * struct globals_s - All globals for the program
 * @line: Line number
 * @file: File name
 * @opcode: opcode
 *
 * Description: Holds the line number and file name
 * for error handling 
 */
struct globals_s
{
	int line;
	char *file;
	char *opcode;
} globals;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Functions */
stack_t *addNode(stack_t **head, int n);
int freeList(stack_t **head);
int popNode(stack_t **head);
stack_t *initStack(int value);
void printList(stack_t **head, unsigned int line);
void (*opFc(stack_t **h, FILE **f))(stack_t **s, unsigned int l);
void printTop(stack_t **head, unsigned int line);
void usageErr(void);
void nopFunc(stack_t **stack, unsigned int line);
void fileErr(void);
void swapFunc(stack_t **stack, unsigned int line);
void addFunc(stack_t **stack, unsigned int line);
void subFunc(stack_t **stack, unsigned int line);
void divFunc(stack_t **stack, unsigned int line);
void mulFunc(stack_t **stack, unsigned int line);
void modFunc(stack_t **stack, unsigned int line);

#endif /* __MONTY__ */
