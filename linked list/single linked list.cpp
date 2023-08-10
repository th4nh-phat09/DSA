#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next; 
};
node* makenode(int x)
{
	node *newnode= new node();
	newnode->data=x;
	newnode->next=NULL;
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
int size(node *head)
{
	int cnt=0;
	while(head!=NULL)
		{
			++cnt;
			head=head->next;
		}
		return cnt;
}
void push_front(node **head,int x)
{
	node *newnode=makenode(x);
	newnode->next=*head;
	*head=newnode;
}
void push_front2(node *&head,int x)
{
	node *newnode=makenode(x);
	newnode->next=head;
	head=newnode;
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
}
void pushback2(node *&head,int x)
{
	node *temp=head;
	node *newnode=makenode(x);
	if(head==NULL)
		{
			head=newnode;
			return;
		}
	while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newnode;
}
void insert(node **head,int k,int x)
{
	int n=size(*head);
	if(k<1||k>n+1)
		return ;
	node *temp=*head;
	if(k==1)
		{
			push_front(head,x);
			return ;
		}
	for(int i=1;i<k-1;i++)
		temp=temp->next;
	node *newnode=makenode(x);
	newnode->next=temp->next;
	temp->next=newnode;
}
void insert2(node *&head,int k,int x)
{
	int n=size(head);
	if(k<1||k>n+1)
		return ;
	node *temp=head;
	if(k==1)
		{
			push_front(&head,x);
			return ;
		}
	for(int i=1;i<k-1;i++)
		temp=temp->next;
	node *newnode=makenode(x);
	newnode->next=temp->next;
	temp->next=newnode;
}
void popfront(node **head)
{
	if(*head==NULL)
		return ;
	node *temp=*head;
	*head=(*head)->next;
	delete temp;
	temp=NULL;
}
void popback(node **head)
{
	int n=size(*head);
	if(*head==NULL)
		return ;
	node *temp=*head;
	if(temp->next==NULL)
		{
			*head=NULL;
			delete temp;
			return ;
		}
	for(int i=1;i<n-1;i++)
		temp=temp->next;
	node *last=temp->next;
		temp->next=NULL;
		delete last;
	
}
void erase(node **head,int k)
{
	int n=size(*head);
	if(k<1||k>n)
		return ;
	node *temp=*head;
	if(k==1)
		{
			popfront(head);
			return ;
		}
	for(int i=1;i<k-1;i++)
		temp=temp->next;
	node *newnode=temp->next;
	temp->next=(temp->next)->next;
	delete newnode;
	newnode=NULL;
}
int main()
{
	node *head=NULL;
		//cout<<&head<<"\n";
	for(int i=1;i<=5;i++)
		{
			pushback2(head,i);
			//cout<<&head<<"\n";
		}
	erase(&head,1);
	duyet(head);
}
