int queue[10]={0}, top=0, buttom=0;

void enuqeue(int value)
{
     if(top==10)
     {
         printf("Queue Full");
         return;
     }
     queue[top]=value;
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
}
void show()
{
     if(buttom==top)
     {
        printf("Queue Is Empty");
        return;      
     }
     
     while(buttom!=top)
     {
         printf("Value %d : %d\n",buttom,queue[buttom]);
         buttom++;              
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
 show();
 system("PAUSE");
}
