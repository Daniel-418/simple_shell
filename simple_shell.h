#ifndef GUARD_H
#define GUARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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


/* Global variable */
extern char **environ;

int execute_command(const char *pathname, char *const argv[],
		char *const envp[], char *program_name);
void display_prompt(char *prompt);
char **split_string(char *str, char *delimeter);
char *_getenv(char *var);
void shell_loop(char *program_name, char *prompt);
list_t *getenvdirs(char *var);
char *get_command_path(char *command); 


/* lists utility functions */
int add_element(list_t **list, char *element);
ssize_t get_size(list_t *list);
list_t *get_node(list_t *list, int index);
int free_list(list_t *list);
int free_str_array(char **arr);
int print_list(list_t *list);


/* string utility functions */
char *_strdup(char *str);
size_t _strlen(const char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *str1, char *str2);
#endif
