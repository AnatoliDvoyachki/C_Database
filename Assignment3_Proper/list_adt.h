#pragma once
#include <stdint.h>

typedef struct node* node_t;

typedef node_t* list_t; // linked list ADT

list_t create_list(); //create the list

int add_item(list_t list, void* elemnt);// return 0 if item added, else -1 

void* get_item(list_t list, uint16_t index); // return pointer to item at a given index in the list 

int no_of_items(list_t list); // returns the number of items in list 

int remove_item(list_t self, void* element); // return 0 if item is removed, else -1
