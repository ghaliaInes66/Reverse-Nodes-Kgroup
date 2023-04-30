#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void add_node(node **head,int val){
       	node *p=(node*)malloc(sizeof(node));
		p->data=val;
		p->next=NULL;
		if(*head==NULL)
		{
			*head=p;}
		else{
			node *q=*head;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
		}	
}

void display_list(node **head){
	if(*head==NULL){
		printf("list is empty");
	}
	else{
		node *p=*head;
		while(p!=NULL)
		{
			printf("\n%i\n",p->data);
			p=p->next;
		}
		}
}

int length(node **head){
	if(*head==NULL){
		printf("list is empty");
		return 0;
	}
	else{
		node *p=*head;int count=0;
		while(p!=NULL){
			p=p->next;
			count++;
		}
		return count;
	}
}

node* reveseKgroup(node **head,int k){
	int l=length(&*head);
  node *p=*head,*t[l]; int i=0,j;
  while (p!=NULL)
  {
    t[i]=p;
    p=p->next;
    i++;
  }
	if(k<=l){
		*head=t[k-1];
	}
  for(i=0;i+k-1<l;i=i+k){
    for(j=i+k-1;j>i;j--){
      t[j]->next=t[j-1];
    }
		if(i+k+k-1<l){
    t[j]->next=t[i+k+k-1];
		}
		else if(i+k==l){
			t[j]->next=NULL;
		}else{
		t[j]->next=t[i+k];
		}
  }

  return *head;
  
}

int main(){
  node *head=NULL;
  add_node(&head,1);
  add_node(&head,2);
	add_node(&head,3);
	add_node(&head,4);

  head=reveseKgroup(&head,4);
  display_list(&head);
}