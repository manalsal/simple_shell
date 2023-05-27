#include "shell.h"

/**
* handle_error - Prints an error message to stderr
* @message: The error message to be printed
*
* Description: This function prints the given error message to the standard
* error stream (stderr).
*/

void handle_error(const char *message)
{
fprintf(stderr, "%s\n", message);
}
#include "shell.h"

/**
* handle_input - Handle user input for shell commands.
*
* @input: User input string.
* @envp: Array of environment variables.
* - The input string should be null-terminated.
* - The envp array should be properly set with environment variables.
*/
void handle_input(char *input, char *envp[])
{
if (my_substr(input, "|"))
{
/* Handles pipeline command */
my_pipline_handler(input, envp);
}
else
{
/* Handles the regular command */
handle_command(input, envp);
}
}

