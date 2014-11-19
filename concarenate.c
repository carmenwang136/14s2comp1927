// concatenate.c
// join two lists
// richard buckland 19 may 2014
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
 
#include "list3-core.h"
 
 
// simple unit tests on the list
static void testList (void);
void showList (list l);
 
 
// join two lists
 
// move all the elements from the second list to the end of
// the first list (in order).  this leaves the second list
// empty and all the elements in the first list. 
void concatenate (list to, list from);
 
 
 
int main (int argc, char *argv[])  {
    printf("testing concatenate\n");
    testList();
    printf ("All tests passed.  You are awesome!\n");
    return EXIT_SUCCESS;
}
 
void concatenate (list to, list from) {
   // dont make new nodes, just move old ones

   assert(to != NULL);
   assert (from != NULL);

   // if to list is empty
   if (to !=NULL || from != NULL) {
        
        if (to->head == NULL) {
         to->head = from->head;
         link current = from->head;

            while (current->next != NULL) {
                current = current->next;
            }
            
        } else if (from->head == NULL) {
            to->head = to->head;
            link current = to->head;

            while (current->next != NULL) {
                current = current->next;
            }
       
       } else {
         //find end of to list to
         link current = to->head;
         while (current->next != NULL) {
            current = current->next;
         } 
         current->next = from->head;
       }
   }

   from->head = NULL;

}
 
list newList(void) {
   list new = malloc (sizeof(*new));
   assert (new != NULL);
   new->head = NULL;
   return new;
}
 
 
static void testList (void) {
    printf ("testing newList()\n");
    list testList = newList();
    assert (testList->head == NULL);
 
 
    printf ("testing concatenate()\n");
 
    // (3,2) -> (5,0)
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    // create a two element list
    list testListB = newList();
 
    testListB->head = malloc (sizeof (node));
    testListB->head->value = 1;
    testListB->head->next  = malloc (sizeof (node));
    testListB->head->next->value = 5;
    testListB->head->next->next  = NULL;
 
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
    // (5,0) -> (5,0)
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
    // (0,5) -> (5,0)
    concatenate (testListB, testList);
    assert (testList != NULL);
    assert (testList->head == NULL);
 
    assert (testListB != NULL);
    assert (testListB->head != NULL);
    assert (testListB->head->value == 3);
    assert (testListB->head->next != NULL);
    assert (testListB->head->next->value == 1);
    assert (testListB->head->next->next != NULL);
    assert (testListB->head->next->next->value == 4);
    assert (testListB->head->next->next->next != NULL);
    assert (testListB->head->next->next->next->value == 1);
    assert (testListB->head->next->next->next->next != NULL);
    assert (testListB->head->next->next->next->next->value == 5);
    assert (testListB->head->next->next->next->next->next == NULL);
}
 
 
void showList (list l) {
 
    assert (l !=NULL);
 
    // start at the first node
    link current = l->head;
    while (current != NULL) {
        printf ("[%d] -> ", current->value);
        current = current->next;
    }
    printf ("X\n");
}