//#include <stdio.h>
//#include <stdlib.h>
#include<bits/stdc++.h>
// Structure for a node
struct Node {
    int data;
    Node* next;
};
Node* makenode(int x)
{
	Node *newnode=new Node();
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
// Function to insert a node at the
// beginning of a Circular linked list
void pushfront(Node** head,int x)
{
  
    // Create a new node and make head
    // as next of it.
    Node* newnode=makenode(x);
    	  newnode->next=*head;
    // If linked list is not NULL then
    // set the next of last node
    if (*head!= NULL)
		{
        // Find the node before head and
        // update next of it.
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newnode;
    	}
    else
        // For the first node
        newnode->next =newnode;
    *head=newnode;
}
  
// Function to print nodes in a given
// circular linked list
void printList(Node* head)
{
   Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
  
    printf("\n");
}
// Function to delete a given node
// from the list
void erase(Node** head, int key)
{
    // If linked list is empty
    if (*head == NULL)
        return; 
    // If the list contains only a
    // single node
    if ((*head)->data == key && (*head)->next == *head)
	{
        delete *head;
        *head = NULL;
        return;
    }
  
    Node *last = *head, *d;
  
    // If head is to be deleted
    if ((*head)->data == key) {
  
        // Find the last node of the list
        while (last->next != *head)
            last = last->next;
  
        // Point last node to the next of
        // head i.e. the second node
        // of the list
        last->next = (*head)->next;
        delete *head;
        *head = last->next;
        return;
    }
  
    // Either the node to be deleted is
    // not found or the end of list
    // is not reached
    while (last->next != *head && last->next->data != key) {
        last = last->next;
    }
  
    // If node to be deleted was found
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        delete d;
    }
    else
        printf("Given node is not found in the list!!!\n");
}
  
// Driver code
int main()
{
    // Initialize lists as empty
    struct Node* head = NULL;
  
    // Created linked list will be
    // 2->5->7->8->10
    pushfront(&head, 2);
    pushfront(&head, 5);
    pushfront(&head, 7);
    pushfront(&head, 8);
    pushfront(&head, 10);
  
    printf("List Before Deletion: ");
    printList(head);
  
    erase(&head, 7);
  
    printf("List After Deletion: ");
    printList(head);
  
    return 0;
}
