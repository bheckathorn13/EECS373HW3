#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	//Check to see if new element needs to inserted
	//up front
	if (new_element->index < head->index) {
		//Set new element next pointer equal to head
		new_element->next = head;
		//Set head equal to new_element
		head = new_element;
		//Return head
		return head;
	}//if
	//Create temp variable to hold current index
	list_t* place = head;
	//Loop until end of list is reached
	while (1) {
		//Check to see if element is at end of list
		if (place->next == NULL) {
    		//Set index next equal to new element
    		place->next = new_element;
    		//Set new_element next element to null
    		new_element->next = NULL;
    		//break loop
    		break;
		}//else if
		//Check to see if new_element is less than next element
		else if (place->next->index > new_element->index) {
			//Set new element next pointer to place->next
			new_element->next = place->next;
			//Set place pointer equal to new element
			place->next = new_element;
			//Break loop
			break;
		}//if
		//Increment index
		place = place->next;
	}//while
	return head;
}//insert_sorted

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	//Temp variable for new head
	list_t* newHead = NULL;
	//temp variable to hold current index
	list_t* place = head;
	//Variable to hold number of elements in list
	int count = 0;
	//Search for end of linked list
	while (1) {
		//Check to see if end of list has been reached
		if (place->next == NULL) {
			//Set end equal to new head
			newHead = place;
			//Set newHead next equal to NULL
			newHead->next = NULL;
			//break loop
			break;
		}//if
		//Increment place
		place = place->next;
		//Increment counter
		++count;
	}//while
	//Temp pointer to hold position in new list
	list_t* place2 = newHead;
	//Loop until original list has been reversed
	while (count > 0) {
		//Reset place
		place = head;
		//Loop to desired position
		int i = 0;
		for (i; i < count - 1; ++i) {
			//Increment index
			place = place->next;
		}
		//Add next element to list
		place2->next = place;
		//Increment new list index
		place2 = place2->next;
		//Create end of list
		place2->next = NULL;
		//Decrement count
		--count;
	}//while
	return newHead;
}//reverse
