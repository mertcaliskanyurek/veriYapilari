#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int value;
	struct Node *next;
}Node;
Node *head=NULL,*tail=NULL;
void enqueue(int _value){
     Node *newNode = (Node*)malloc(sizeof(Node));
     newNode->value = _value;
     newNode->next = NULL;
     if(tail==NULL)
     {                 
                   head=newNode;
                   tail=newNode;
     }
     else if(tail->next==NULL)
     {
                   head=newNode;
                   tail->next = head;
     }
     else
     {
                   head->next = newNode;
                   head=newNode;
     }
     
     
}
void dequeue()
{
     if(tail==NULL)
     {
                   printf("Queue is empty\n");
                   return;
     }
     if(tail->next==NULL)
     {
                         tail=NULL;
                         head=NULL;
     }else
          tail = tail->next;
}
void show()
{
     if(tail==NULL)
     {
                   printf("Queue is empty\n");
                   return;
     }
     Node *temp = tail;
     while(temp!=NULL)
     {
                      if(temp==tail)
                          printf("[Tail]");
                      
                      if(temp==head)
                          printf("[Head]");
                          
                      printf(" %d, ",temp->value);
                      temp=temp->next;
     }
}
main()
{
    enqueue(60);
    dequeue();
    enqueue(70);
    enqueue(50);
    enqueue(20);
    enqueue(10);
    enqueue(40);
    dequeue();

	show();
	system("PAUSE");
}
