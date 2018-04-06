int queue[10]={0}, top=0, buttom=0;
void enuqeue(int value)
{
     if(top==buttom && top!=0)
     {
         printf("Queue Full");
         return;
     }
     queue[top%10]=value;
     top++;
}
void dequeue()
{
    if(top==buttom)
    {
        printf("Queue Is Empty");
        return;
    }
    buttom++;
    buttom%=10;
}
void show()
{
     if(buttom==top)
     {
        printf("Queue Is Empty");
        return;      
     }
     int i=buttom;
     while(i<top)
     {
         printf("Value %d : %d\n",i,queue[i]);
         i++;              
     }
}
main() 
{
 enuqeue(5);
 enuqeue(9);
 enuqeue(7);
 dequeue();
 dequeue();
 enuqeue(12);
 enuqeue(52);
 enuqeue(11);
 enuqeue(15);
 dequeue();
 dequeue();
 show();
 system("PAUSE");
}
