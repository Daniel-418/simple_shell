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

int execute_command(const char *pathname, char *const argv[],
		char *const envp[], char *program_name);
void display_prompt(char *prompt);
char **split_string(char *str, char *delimeter);


/* list struct */
/**
 * struct list_s - single linked list
 * @str: string (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* lists utility functions */
int add_element(list_t **list, char *element);
ssize_t get_size(list_t *list);
list_t *get_node(list_t *list, int index);
int free_list(list_t *list);

/* string utility functions */
char *_strdup(char *str);
size_t _strlen(const char *str);
#endif
