#include<bits/stdc++.h>
using namespace std;
struct SV
{
	string name;
	int tuoi;
};
struct node
{
	SV data;
	node *next;
};
node* makenode(SV x)
{
	node *newnode=new node();
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
void duyet(node *head)
{
	while(head!=NULL)
		{
			cout<<head->data.name<<" "<<head->data.tuoi<<"\n";
			head=head->next;
		}
}
void pushback(node **head,SV x)
{
	node *newnode=makenode(x);
	if(*head==NULL)
		{
			*head=newnode;
			return ;
		}
	node *temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
}
int main()
{
	SV a,b;
	a.name="phat";
	a.tuoi=19;
	b.name="nguyen";
	b.tuoi=29;
	node *head=NULL;
	pushback(&head,a);
	pushback(&head,b);
	duyet(head);
	return 0;
}
