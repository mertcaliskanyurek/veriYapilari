#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Eleman{
	int ogrNo; //key
	char isim[50];
	int dogumYili;
}Eleman;
typedef struct HashNode{
	Eleman *e;
	struct HashNode *next;
}HashNode;

HashNode** hash;

int HashFunc(int key){
	return key%10;
}

void addToHash(Eleman *e)
{
	int indis = HashFunc(e->ogrNo);
	HashNode *temp = (HashNode*) malloc(sizeof(HashNode));
	temp->e = e;
	temp->next = NULL;
	
	if(hash[indis]==NULL)
		hash[indis]=temp;
	else{
		HashNode *iter = hash[indis];
		for(;iter->next!=NULL;iter=iter->next);
		
		iter->next=temp;
	}
}

void printHasH()
{
	int i;
	printf("Hash :\n");
	for(i=0;i<10;i++)
	{
		if(hash[i]==NULL)
			printf("%d \n",i);
		else
		{
			printf("%d ",i);
			HashNode *iter = hash[i];
			while(iter!=NULL)
			{
				printf("->%d",iter->e->ogrNo);
				iter=iter->next;
			}
			printf("\n");
		}
	}
}

Eleman * findInHash(int key)
{
	int indis = HashFunc(key);
	if(hash[indis]==NULL)
		return NULL;
	else
	{
		HashNode *iter = hash[indis];
		while(iter!=NULL && iter->e->ogrNo!=key)
			iter=iter->next;
		
		if(iter==NULL)
			return NULL;
		else
			return iter->e;
	}
}

void delFromHash(int key)
{
	int indis = HashFunc(key);
	
	if(hash[indis]!=NULL)
	{
		HashNode *parent = NULL;
		HashNode *current = hash[indis];
		while(current != NULL && current->e->ogrNo!=key)
		{
			parent = current ;
			current = current->next;
		}
		
		if(current==NULL)
		{
			printf("Eleman Bulunmadi!");
			return;
		}
		
		if(parent==NULL)
			hash[indis]= current->next;
		else
			parent->next= current->next;
		
		free(current);
	}
	else
		printf("Eleman Bulunmadi");
}
/*
void delFromHash2(int key)
{
	Eleman *e= findInHash(key);
	
}*/
int main()
{
	hash = (HashNode**) calloc(10,sizeof(HashNode*));
	int i;
	for(i=0;i<10;i++)
	{
		Eleman *e= (Eleman*) malloc(sizeof(Eleman));
		scanf("%d %s %d",&e->ogrNo,&e->isim,&e->dogumYili);
		addToHash(e);
	}
	
	printHasH();
	printf("\n\n Bulma Testi | Bir OgrNo Girin :");
	int k;
	scanf("%d",&k);
	Eleman *e = findInHash(k);
	if(e!=NULL)
		printf("%d %s %d",e->ogrNo,e->isim,e->dogumYili);
	else
		printf("Bulunamadi");
		
	printf("\n\n Silme Testi | Bir OgrNo Girin :");
	scanf("%d",&k);
	delFromHash(k);
	printHasH();
	return 0;	
}
