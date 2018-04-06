int stack[10]={0}, top=0;
void push(int value)
{
     if(top==10)
     {
         printf("Stack Dolu");
         return;
     }
     stack[top]=value;
     top++;
}
void pop()
{
    if(top==0)
    {
        printf("Stack Is Empty");
        return;
    }
    top--; 
}
void show()
{
     int buttom=0;
     if(buttom==top)
     {
        printf("Stack Is Empty");
        return;      
     }
     
     while(buttom!=top)
     {
         printf("Value %d : %d\n",buttom,stack[buttom]);
         buttom++;              
     }
}
main() {
push(5);
push(9);
push(7);
pop();
pop();
push(12);
show();
system("PAUSE");
}
