/*
 * File: 103-find_loop.c
 * Auth: Ojo Yusuf
 */

#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *snail, *hare;

	if (head == NULL || head->next == NULL)
		return (NULL);

	snail = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (snail == hare)
		{
			snail = head;

			while (snail != hare)
			{
				snail = snail->next;
				hare = hare->next;
			}

			return (snail);
		}

		snail = snail->next;
		hare = (hare->next)->next;
	}

	return (NULL);
}
