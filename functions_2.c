#include "monty.h"

/**
 * nop - Implementation of the nop function (does nothing)
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /*Suppress unused variable warning*/
	(void)line_number; /*Suppress unused variable warning*/
	/*This function does nothing*/
}


/**
 * swap - Implementation of the swap function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * pint - Implementation of the pint function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
