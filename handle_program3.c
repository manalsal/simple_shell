#include "shell.h"

/**
 * waitForChildProcess - Waits for the completion of a child process
 * @childPid: The process ID of the child process
 *
 * Return: The exit status of the child process
 */
int waitForChildProcess(pid_t childPid)
{
int status;

if (waitpid(childPid, &status, 0) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}

if (WIFEXITED(status))
{
return (WEXITSTATUS(status));
}
else if (WIFSIGNALED(status))
{
fprintf(stderr, "Error with child process\n");
exit(EXIT_FAILURE);
}
return (-1);
}
#include "shell.h"

/**
 * ExecuteCmd - Executes a command using execvp.
 * @cmd: The command to execute
 *
 *  Return: 0
 */
void ExecuteCmd(char *cmd)
{
char *arguments[4];

arguments[0] = "sh";
arguments[1] = "-c";
arguments[2] = cmd;
arguments[3] = NULL;

execvp("/bin/sh", arguments);
perror("execvp");
exit(EXIT_FAILURE);
}

/**
 * executeSystemCustom - Executes a custom system command
 * @cmd: The command to execute
 * @inputFd: Input file descriptor
 *
 * Return: The exit status of the executed command
 */
int executeSystemCustom(char *cmd, int inputFd)
{
int exitStatus;
pid_t childPid = createChildProcess(&inputFd);

if (childPid == 0)
{
ExecuteCmd(cmd);
}
exitStatus = waitForChildProcess(childPid);
return (exitStatus);
}

