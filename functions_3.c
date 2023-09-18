#include "monty.h"

/**
 * sub - Implementation of the sub function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->next->n - (*stack)->n;

	(*stack)->next->n = result;
	pop(stack, line_number); /* Pop the top element after subtraction */
}

/**
 * _div - Implementation of the _div function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->next->n / (*stack)->n;

	(*stack)->next->n = result;
	pop(stack, line_number); /* Pop the top element after division */
}

/**
 * mul - Implementation of the mul function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->next->n * (*stack)->n;

	(*stack)->next->n = result;
	pop(stack, line_number); /* Pop the top element after multiplication */
}

/**
 * mod - Implementation of the mod function
 * @stack: A pointer to the top of the stack
 * @line_number: The current line number
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	int result = (*stack)->next->n % (*stack)->n;

	(*stack)->next->n = result;
	pop(stack, line_number); /* Pop the top element after computing remainder */
}
/**
 * is_printable - Function to check if a character is printable ASCII
 * @value: stores to input that will be chace to character
 * Return: the printable character
 */

int is_printable(int value)
{
	return (value >= 32 && value <= 126);
}
