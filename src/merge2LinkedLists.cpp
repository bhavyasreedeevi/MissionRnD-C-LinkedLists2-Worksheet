/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node *current;
struct node *list = NULL;
struct node* createlist(int data)
{
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->num = data;
	new_node->next = NULL;
	if (list == NULL)
	{
		list = new_node;
		current = new_node;
	}
	else
	{
		current->next = new_node;
		current = new_node;
	}
	return(list);
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 != NULL&&head2 == NULL)
		return head1;
	else if (head2 != NULL&&head1 == NULL)
		return head2;
	list = NULL;
	int temp, i, k = 0;
	struct node *result = NULL, *temp1 = head1, *temp2 = head2;
	while (temp1 != NULL&&temp2 != NULL)
	{
		if ((temp1->num)< (temp2->num))
		{

			result = createlist(temp1->num);
			temp1 = temp1->next;
		}
		else
		{
			result = createlist(temp2->num);
			temp2 = temp2->next;
		}
	}
	while (temp1 != NULL)
	{
		result = createlist(temp1->num);
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		result = createlist(temp2->num);
		temp2 = temp2->next;
	}
	return result;
}
