#include "monty.h"

/**
 * pchar - Implementation of the pchar function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	int value = (*stack)->n;

	if (!is_printable(value))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(value);
	putchar('\n');

	/* Pop the top element after printing */
	stack_t *temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * pstr - Implementation of the pstr function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}

	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && is_printable(current->n))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - Implementation of the rotl function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
		/* No rotation needed if the stack is empty or has only one element */
	}

	stack_t *first = *stack;         /* Top element becomes the last one */
	*stack = (*stack)->next;         /* Update the stack pointer */
	first->prev = NULL;              /* Set previous of the new top to NULL */
	stack_t *current = *stack;       /* New top element */

	while (current->next != NULL)
	{
		current = current->next;
		/* Traverse the stack to find the last element */
	}

	current->next = first;
	/* Make the top element the last one */
	first->next = NULL;
	/* Set the next of the new last element to NULL */
	first->prev = current;
	/* Set previous of the top element to the new last element */
}

/**
 * rotr - Implementation of the rotr function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
		/* No rotation needed if the stack is empty or has only one element */
	}

	stack_t *last = *stack;
	/* Last element becomes the new top */
	while (last->next != NULL)
	{
		last = last->next;
		/* Traverse the stack to find the last element */
	}

	last->prev->next = NULL;
	/* Disconnect the new last element from the one before it */
	last->next = *stack;
	/* Make the current top the next of the new last element */
	last->prev = NULL;
	/* Set previous of the new top to NULL */
	(*stack)->prev = last;
	/* Set previous of the current top to the new last element */
	*stack = last;
	/* Update the stack pointer to point to the new top */
}


