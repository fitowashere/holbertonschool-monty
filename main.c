#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: The number of command line arguments
 * @argv: An array of strings containing the command line arguments
 * Return: exit on success
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s filename\n", argv[0]);
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack_t *stack = NULL;
	char line[256];
	unsigned int line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
		/* Tokenize the line based on spaces and newlines */
		char *token = strtok(line, " \n");

		if (token == NULL || *token == '#')
		{
			continue; /*Ignore empty lines and comments*/
		}
		void (*fun)(stack_t **, unsigned int) = get_fun(token);

		if (fun)
			fun(&stack, line_number);
		else
		{
			fprintf(stderr, "L%u: Error: Unknown instruction %s\n",line_number, token);
			return (EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	free_stack(&stack); /*Free the stack to prevent memory leaks*/
	return (EXIT_SUCCESS);
}
