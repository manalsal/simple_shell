#include "shell.h"

/**
* my_exit - Exit the shell with a given status
* @argument: The argument array passed to the function
*
* Description: This function exits the shell with a given status. If an
* argument is provided, it is converted
* to an integer and used as the exit status.
* The function also frees the memory allocated for the argument array.
*/
void my_exit(char **argument)
{
int MM_stat = 0, a;

if (argument[1] != NULL)
{
MM_stat = atoi(argument[1]);
}

for (a = 0; argument[a] != NULL; a++)
{
free(argument[a]);
}

free(argument);
exit(MM_stat);
}
#include "shell.h"

/**
* file_check - check if the command file exists in /bin/
* @cmd_token: token to check
*
* Return: NULL if not found, otherwise the full path to the command
**/
char *file_check(char *cmd_token)
{
DIR *dir = opendir("/bin/");    /* Open the /bin/ directory */
struct dirent *entry;

if (dir == NULL)
{
perror("opendir");      /* Print an error message if opendir fails */
return (NULL);
}

while ((entry = readdir(dir)) != NULL)
{
char *dir_entry = entry->d_name;

if (strcmp(dir_entry, cmd_token) == 0)
{
/* Allocate memory for the command path */
char *command_path = malloc(my_strlen("/bin/") + my_strlen(cmd_token) + 1);

if (command_path == NULL)
{
closedir(dir);
perror("malloc");       /* Print an error message if malloc fails */
return (NULL);
}

command_path = strcpy(command_path, "/bin/");
/* Copy "/bin/" to the command path */
command_path = my_strcat(command_path, cmd_token);
/* Concatenate the command token to the command path */
closedir(dir);  /* Close the directory */
return (command_path);
}
}

closedir(dir);  /* Close the directory */
return (NULL);
}

