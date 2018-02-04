#include "list_adt.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

struct node
{
	void* element;
	struct node* next;
};

list_t create_list()
{
	list_t head = (list_t)malloc(sizeof(list_t));
	*head = NULL;
	return head;
}

int add_item(list_t self, void* element)
{
	node_t new_node = (node_t)malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		return -1; // out of memory
	}
	new_node->element = element;
	new_node->next = *self;
	*self = new_node; // dereferencing
	return 0;
}

// helper function to remove the head of the list
void remove_front(list_t self)
{
	node_t head = *self;
	if (head == NULL)
	{
		return;
	}
	*self = head->next;
	head->next = NULL;
	if (head == *self)
	{
		*self = NULL;
	}
	free(head);
}

// helper function that removes the back node of the list
void remove_back(list_t self)
{
	if (self == NULL)
	{
		return;
	}
	node_t current = *self;
	node_t previous = NULL;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	if (previous != NULL)
	{
		previous->next = NULL;
	}
	if (current == *self)
	{
		*self = NULL; // if this is the last node of the list
	}
	free(current);
}

int remove_item(list_t self, void* element)
{
	node_t current = *self;
	if (current == NULL || element == NULL)
	{
		return -1; // list is empty or element is null
	}
	if (current->element == element)
	{
		remove_front(self); // remove the head
		return 0;
	}
	if (current->next == NULL)
	{
		remove_back(self); // remove the last element
		return 0;
	}
	// remove from the middle
	while (current != NULL)
	{
		if (current->next->element == element)
		{
			break;
		}
		current = current->next;
	}
	if (current != NULL)
	{
		node_t temp_node = current->next;
		current->next = temp_node->next;
		temp_node->next = NULL;
		free(temp_node);
	}
	return 0;
}

int no_of_items(list_t self)
{
	if (*self == NULL) // check for null
	{
		return 0;
	}
	node_t current = *self;
	int count = 0;
	while (current != NULL) // loop until no more elements
	{
		count++; // update counter
		current = current->next; // get the next element
	}
	return count;
}

void* get_item(list_t self, uint16_t index)
{
	node_t current = *self;
	uint16_t i = 0;
	while (current != NULL)
	{
		if (i == index)
		{
			return current->element;
		}
		current = current->next;
		i++;
	}
	return NULL;
}
