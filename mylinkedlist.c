#include "mylinkedlist.h"

/*************************
*Function Name: add_to_list
*Summary: adds a number to the list
*Inputs: a struct and an int
*outputs: a struct

***********************
*psedocode:
*begin
* create a new node
* allocate memory
* if the new_node = null
*  display error message
* end if
* set the new nodes value to n
* set the new nodes pointer to first 
* return the new_node
*end
***********************/	

struct node *add_to_list (struct node *first, int n)
{

	struct node *new_node;
new_node = malloc(sizeof(struct node));
		if (new_node == NULL)
		{
			printf("Error: Malloc failed in fsort");
			exit(EXIT_FAILURE);
		}
		new_node->value = n;
		new_node->next = first;
		return new_node;
}
/*************************
*Function Name: bubbleSort
*Summary: sorts the list in numerical order smallest to largest
*Inputs: a struct
*outputs: a struct
*neads to be paired with the swap function below and can be used in future projects
***********************
*psedocode:
*begin
* create 2 temp structs setting 1 equal to 1
* while true do
*  set a into to 0
*  set one temp to first
*  while the next value isnt null
*   if the value of one is greater then the next 
*    run the swap function
*    set swapped to 1
*   endif
*   set one temp to another
*   while swapped retun first
*end
***********************/
struct node *bubbleSort (struct node *first)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
   

    do
    {
        swapped = 0;
        ptr1 = first;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->value > ptr1->next->value)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
	return first;
}
 /*************************
*Function Name: swap
*Summary: swaps the input structs
*Inputs: 2 structs
*outputs: void

***********************
*psedocode:
*begin
* int temp
* sets tempt to a value
* sets a to b value
* sets b value to temp
*end
***********************/

void swap(struct node *a, struct node *b)
{
    int temp;
	temp = a->value;
    a->value = b->value;
    b->value = temp;
}
/*************************
*Function Name: removeDuplicates
*Summary: removes duplicates fromt the linked list
*Inputs: a struct
*outputs: a struct

***********************
*psedocode:
*begin
* create a current node and = first
* create a pointer to store the next node if it needs to be deleted.
* if current = null 
*  returns first //used ato do nothing if the list is empty
* endif
* while current pointer next is not null
*  if the curren value is = to value next
*   set next next to curent next nxet
*   free the curren next struct
*   set current next to next next.
*  else
*   current = curent next //advances for no deletion
*  endif
* Return first
*end
***********************/

struct node *removeDuplicates (struct node *first)
{
    /* Pointer to traverse the linked list */
    struct node *current = first;
 
    /* Pointer to store the next pointer of a node to be deleted*/
    struct node *next_next; 
   
    /* do nothing if the list is empty */
    if (current == NULL) 
       return first; 
 
    /* Traverse the list till last node */
    while (current->next != NULL) 
    {
       /* Compare current node with next node */
       if (current->value == current->next->value) 
       {
           /* The sequence of steps is important*/              
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
       else /* This is tricky: only advance if no deletion */
       {
          current = current->next; 
       }
    }
	return first;
}