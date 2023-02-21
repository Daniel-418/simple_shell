#ifndef GUARD
#define GUARD
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

/*prompt to display.*/
#define PROMPT "$ "

/*pointer to the address of the shell environmental variables*/
extern char **environ;

/*-----FUNCTIONS-----*/

/*Executes the command passed on the command line*/
int execute_command(char *command, char **args, char** environ);
/*Tokenizes a string*/
char **tokenize_string(char *str, char *delimeter);
#endif
