#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
node* makenode(int x)
{
	node *newnode=new node();
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}
void duyet(node *head)
{
	while(head!=NULL)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
}
int sz(node *head)
{
	int cnt = 0;
	while(head != NULL){
		++cnt;
		head = head->next;
	}
	return cnt;
}
void pushfront(node **head,int x)
{
	node *newnode=makenode(x);
	newnode->next=*head;
	if(*head!=NULL)
		(*head)->prev=newnode;
	*head=newnode ;
}
void pushback(node **head,int x)
{
	node *temp=*head;
	node *newnode=makenode(x);
	if(*head==NULL)
		{
			*head=newnode;
			return;
		}
	while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newnode;
	newnode->prev=temp;
}
void insert(node **head, int x, int k)
{
	int n = sz(*head);
	if(k < 1 || k > n + 1) return;
	if(k == 1)
		{
			pushfront(head, x); 
			return;
		}
	node *temp = *head;
	for(int i = 1; i <= k - 1; i++)
		temp = temp->next;
	node *newNode = makeNode(x);
	newNode->next = temp;
	temp->prev->next = newNode;
	newNode->prev = temp->prev;
	temp->prev = newNode;
}
int main()
{
	node *head=NULL;
	for(int i=1;i<=5;i++)
	pushfront(&head,i);
	duyet(head);
	return 0;
}
