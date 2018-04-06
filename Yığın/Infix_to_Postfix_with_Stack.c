#include<stdio.h>
#include<string.h>
#define stackSize 100
char stack[stackSize];
short int top=0;
void push(char value)
{
     if(top==stackSize)
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
        printf("Stack Bos");
        return;
    }
    top--; 
}
//gelen operatorun onceligine gore deger dondurur
short int degerDondur(char ifade)
{
    if(ifade == '^')
      return 3;
    else if(ifade == '*' || ifade == '/')
       return 2;
    else if(ifade == '+' || ifade == '-')
        return 1;
    else return -1;
}
main()
{
      char ifade[100];
      int i=0,j=0; //i okunan ifade katarinin indisi, j postfix katarinin indisi
      printf("Ifadeyi girin (Max 100) (Or: (a+b)-c): \n");
      gets(ifade);
      char temp[sizeof(ifade)];
      char postfix[sizeof(ifade)];
      
      while(ifade[i]!='\0')
      {
             //ifade ac parantez ise
             if(ifade[i]=='(')
                 push(ifade[i]);
             //ifade operator ise    
             else if(ifade[i]=='+' || ifade[i]=='-' 
                   || ifade[i]=='*' || ifade[i]=='/' || ifade[i]=='^')
             {
                     //yigin bos ise
                     if(top==0)
                        push(ifade[i]);
                     else
                     {
                          while(degerDondur(stack[top])>degerDondur(ifade[i]))
                          {
                                   postfix[j]=stack[top-1];
                                   j++;
                                   pop();
                          }//stackteki operatorun onceligi daha kucuk olana kadar
                          push(ifade[i]);
                      }
             }
             //ifade kapa parantez ise
             else if(ifade[i]==')')
             {
                  while(stack[top-1]!='(')
                  {
                       postfix[j]=stack[top-1];
                       j++;
                       pop();
                  }//stackte ac parantez gorene kadar
                  pop(); //en sonki ac parantez karakterini de at
             }
             else
             {
                postfix[j]=ifade[i];
                j++;
             }
             i++;  
      }//
      
      while(top>0)
      {
            postfix[j]=stack[top-1];
            j++;
            pop();
      }
      postfix[j]='\0'; //katarý olusturma sonlandi
      printf("Postfix ifadesi :\n %s \n",postfix);
      system("PAUSE");
      return 0;
}
