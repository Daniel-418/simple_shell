#include "simple_shell.h"

/**
 * add_element - adds an element to a list
 * @list: the list
 * @element: the element
 *
 * Return: always 0
 */
int add_element(list_t **list, char *element)
{
	list_t *temp;
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (-1);

	new_node->next = NULL;
	new_node->str = _strdup(element);
	new_node->len = _strlen(new_node->str);
	if (*list == NULL)
	{
		*list = new_node;
		return (0);
	}

	temp = *list;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;

	return (0);
}

/**
 * get_size - gets the size of a list
 * @list: the list
 *
 * Return: the size of the list
 */
ssize_t get_size(list_t *list)
{
	list_t *temp;
	ssize_t counter;

	if (list == NULL)
		return (0);

	temp = list;
	counter = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}

	return (counter);
}

/**
 * free_list - frees a list
 * @list: the list
 *
 * Return: 0 if successful;
 */
int free_list(list_t *list)
{
	list_t *temp;
	list_t *next_node;

	if (list == NULL)
		return (-1);

	temp = list;
	while (temp != NULL)
	{
		next_node = temp->next;
		free(temp->str);
		free(temp);
		temp = next_node;
	}

	return (0);
}

/**
 * get_node - gets the node at a particular index of a list
 * @list: the list
 * @index: The index wher the node is to be gotten from
 *
 * Return: A node of the list gottent
 */
list_t *get_node(list_t *list, int index)
{
	int current_index = 0;
	list_t *current_node = list;

	while (current_node != NULL && current_index < index)
	{
		current_node = current_node->next;
		current_index++;
	}

	if (current_index != index)
	{
		return (NULL);
	}

	return (current_node);
}

/**
 * print_list - prints a list
 * @list: the list to be printed
 *
 * Return: 0 if successful, -1 if not
 */
int print_list(list_t *list)
{
	list_t *temp;

	if (list == NULL)
		return (-1);
	temp = list;

	while (temp != NULL)
	{
		if (write(STDOUT_FILENO, temp->str, temp->len) == -1)
			return (-1);
		if (write(STDOUT_FILENO, "\n", 1) == -1)
			return (-1);
		temp = temp->next;
	}

	return (0);
}
