#ifndef GUARD_H
#define GUARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Global variable */
extern char **environ;
size_t _strlen(const char *str);
int execute_command(const char *pathname, char *const argv[],
		char *const envp[], char *prompt);
void display_prompt(char *prompt);
#endif
