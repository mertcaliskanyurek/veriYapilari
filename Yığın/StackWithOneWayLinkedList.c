#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int value;
	struct Node *previous;
	struct Node *next;
}Node;
Node *top=NULL;
void push(int _value)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = _value;
	if(top==NULL){
		newNode->previous = NULL;
		top = newNode;
	}
	else{
		newNode->previous = top;
		top=newNode;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	
	if(top->previous==NULL)
		top=NULL;
	else
		top=top->previous;
	
}
void show()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
		return;
	}
	Node *temp=top;
	while(temp!=NULL)
	{
		printf("%d\n",temp->value);
		temp=temp->previous;
	}
}
main()
{
    pop();
	push(50);
	push(20);
	push(30);
	push(40);
	pop();
	show();
	system("PAUSE");
}
