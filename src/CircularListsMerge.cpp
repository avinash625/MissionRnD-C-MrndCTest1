/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int length(struct node *head)
{
	int count = 0; 
		struct node* current = head;  
		while (current != NULL)
		{
			count++;
			current = current->next;
		}
		return count;
	
}
void make_it_circular(struct node *head){
	struct node *temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = head;
}
void convert(struct node *head)
{
	struct node *temp = head;
	while (temp->data <= temp->next->data)
		temp = temp->next;
	temp->next = NULL;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *iterator1, *new_head = NULL, *iterator2, *temp= NULL;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1 == NULL && head2 == NULL)
		return NULL;
	else
	{
		for (iterator1 = head1, iterator2 = head2; iterator1 != NULL && iterator2 != NULL;)
		{
			if (iterator1->data >= iterator2->data)
			{
				if (new_head == NULL)
				{
					temp = new_head = iterator2;
				}
				else
				{
					temp->next = iterator2;
					temp = iterator2;
				}
				iterator2 = iterator2->next;
			}
			else
			{
				if (new_head == NULL)
				{
					temp = new_head = iterator1;
				}
				else
				{
					temp->next = iterator1;
					temp = iterator1;
				}
				iterator1 = iterator1->next;
			}
		}
		if (iterator1 != NULL)
		{
			for (; iterator1 != NULL; temp = iterator1, iterator1 = iterator1->next)
				temp->next = iterator1;
		}
		else
		for (; iterator2 != NULL; temp = iterator2, iterator2 = iterator2->next)
			temp->next = iterator2;
	}
	return new_head;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	int result = 0;
	struct node *list1, *list2;
	list1 = *head1;
	list2 = *head2;
	if (list1 == NULL && list2 == NULL)
		return -1;
	else if (list1 == NULL)
	{
		*head1 = *head2;
		return length(list2);
	}
	else if (list2 == NULL)
	{
		return length(list1);
	}
	else
	{
		convert(list1);
		convert(list2);
		result = result + length(list1);
		result += length(list2);
		*head1 = merge2LinkedLists(list1, list2);
		make_it_circular(*head1);
		return result;
	}
}