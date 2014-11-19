// Core functions for linked list ADT
// Comp1917 material
// Carmen Wang

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list3-core.h"


// print out a list
void showList (list listToPrint) {
    assert (listToPrint != NULL);
    
    link current = listToPrint->head;
   
    while (current != NULL) {
        printf("[%d]->", current->value);
        current = current->next;
    }

    printf ("X\n");
}

// inset item at the front of the list
void frontInsert (list l, int item) {
    assert (l != NULL);

    link oldFirstnode = l->head;
    link newFirstnode = malloc(sizeof(node));
    assert (newFirstnode != NULL);

    newFirstnode->value = item;
    newFirstnode->next = oldFirstnode;
    l->head = newFirstnode;
}

// count the number of items in the list
int numItems (list l) {
    int count = 0;
    
    link current = l->head;

    while(current != NULL) {
        count++;
        current = current->next;
    }
    return (count);
}

// insert at end of list
void append (list l, int value) {
    assert (l != NULL);
    
    // create new last node
    link newLastnode = malloc(sizeof(node));
    assert (newLastnode != NULL);
    newLastnode->value = value;
    newLastnode->next = NULL;

    link current = l->head;

    if (current == NULL) {
        newLastnode = l->head;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newLastnode;
    }
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
	assert (l != NULL);

    link current = l->head;

    int counter = 0;

    while (counter != position) {
        current = current->next;
        counter++;
    }
    return current->value;
}

