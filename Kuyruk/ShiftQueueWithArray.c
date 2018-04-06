int queue[10]={0}, top=0;buttom=0;

void enqeue(int value)
{
     if(top==10)
     {
         printf("Queue Full\n");
         return;
     }
     queue[top]=value;
     top++;
}
void dequeue()
{
    if(top==0)
    {
        printf("Queue Is Empty\n");
        return;
    }
    int backup[10]={0};
    int sayac=0,j;
    buttom++;
    while(top>buttom) //kuyrugun sonundan basina kadar yedek alýyoruz , atýilacak elemani almiyoruz
    {
       backup[sayac]=queue[top-1];
       top--;
       sayac++;
    }
    top=0; //son sifir olacak 
    for(j=0;j<sayac;j++) //yedegi geri yukluyoruz
        enqeue(backup[j]);
    
}
void show()
{
     int i=0;
     if(top==0)
     {
        printf("Queue Is Empty\n");
        return;      
     }
     
     while(i<top)
     {
         printf("Value %d: %d\n",i,queue[i]);
         i++;              
     }
}
main() 
{
 enqeue(5);
 enqeue(9);
 enqeue(7);
  enqeue(15);
   enqeue(23);
 enqeue(12);
 dequeue();
 dequeue();
  enqeue(15);
   enqeue(13);
    enqeue(12);
  enqeue(15);
   enqeue(13);
    enqeue(13);
       enqeue(13);


 show();
 system("PAUSE");
}
