/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int count = 0, num, i, pos = 0;
	struct node * curr,*current;
	curr = head;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		count = count + 1;
	}
	current = head;
	pos = count / 2;
	if (count % 2 == 0)
	{
		for (i = 1; i < pos; i++)
		{
			current = current->next;
		}
		num = (current->num + current->next->num) / 2;
	}
	else
	{
		for (i = 1; i <= pos; i++)
		{
			current = current->next;
		}
		num = current->num;
	}
	return(num);
}
