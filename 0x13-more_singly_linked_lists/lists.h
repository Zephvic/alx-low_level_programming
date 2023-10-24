#ifndef _LISTS_
#define _LISTS_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/**
 * struct listp_s - singly linked list
 * @p: pointers of nodes
 * @next: points to the next node
 */
typedef struct listp_s
{
	void *p;
	struct listp_s *next;
} listp_t;

/**
 * print_listint - Prints all the elements of a listint_t list.
 */
size_t print_listint(const listint_t *h);

/**
 * listint_len - Counts the number of nodes in a listint_t list.
 */
size_t listint_len(const listint_t *h);

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 */
listint_t *add_nodeint(listint_t **head, const int n);

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 */
listint_t *add_nodeint_end(listint_t **head, const int n);

/**
 * free_listint - Frees a listint_t list.
 */
void free_listint(listint_t *head);

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 */
void free_listint2(listint_t **head);

/**
 * pop_listint - Removes the head node of a listint_t list.
 */
int pop_listint(listint_t **head);

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index);

/**
 * sum_listint - Returns the sum of all the data (n) of a listint_t list.
 */
int sum_listint(listint_t *head);

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in a listint_t list.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n);

/**
 * delete_nodeint_at_index - Deletes a node at a given index in a listint_t list.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index);

/**
 * reverse_listint - Reverses a listint_t list.
 */
listint_t *reverse_listint(listint_t **head);

/**
 * print_listint_safe - Prints all the elements of a listint_t list safely.
 */
size_t print_listint_safe(const listint_t *head);

/**
 * free_listint_safe - Frees a listint_t list safely.
 */
size_t free_listint_safe(listint_t **h);

/**
 * find_listint_loop - Finds the loop in a listint_t list.
 */
listint_t *find_listint_loop(listint_t *head);

#endif
