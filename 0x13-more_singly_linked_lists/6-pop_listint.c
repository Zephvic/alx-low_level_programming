#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A double pointer to the head of the list.
 *
 * Return: The head node's data (n), or 0 if the linked list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int data = 0;

	if (*head != NULL)
	{
		temp = *head;
		data = temp->n;
		*head = temp->next;
		free(temp);
	}

	return (data);
}
