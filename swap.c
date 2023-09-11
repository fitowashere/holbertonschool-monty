#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *stack;
    temp->prev = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp;
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    temp = last->prev;
    temp->next = NULL;

    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}
