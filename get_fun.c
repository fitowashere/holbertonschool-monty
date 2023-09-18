#include "monty.h"

/**
 * get_fun - Function to get the corresponding function for an opcode
 * @opcode: The opcode to search for
 * Return: A pointer to the corresponding function
 */
void (*get_fun(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"swap", swap},
		{"pint", pint},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		/*Add more opcode-function mappings here*/
		{NULL, NULL}};

	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			return (opcodes[i].f);
		}
		i++;
	}

	return (NULL); /*Opcode not found*/

}
