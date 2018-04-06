#include<stdio.h>
#include<stdlib.h>
typedef struct Dugum{
	int deger;
	struct Dugum *sol; 
	struct Dugum *sag;
}Dugum;
Dugum *kok=NULL;
Dugum *anne=NULL;
void ekle(int deger)
{
	Dugum *yeni = (Dugum*) malloc(sizeof(Dugum));
	yeni->deger = deger;
	yeni->sol=NULL;
	yeni->sag=NULL;
	
	if(kok==NULL){
		kok=yeni;
		anne=yeni;
		return;
	}
	
	if(anne->sol==NULL)
		anne->sol = yeni;
	else if(anne->sag==NULL)
		anne->sag = yeni;
	else{
		anne->sol->sol = yeni;
		anne = anne->sol;
	}
}
void goster(Dugum *baslmNokt){
	if(baslmNokt!=NULL){
		printf(" %d ",baslmNokt->deger);
		goster(baslmNokt->sol);
		goster(baslmNokt->sag);
	}
}
main(){
	ekle(5);
	ekle(8);
	ekle(10);
	ekle(2);
	ekle(6);
	ekle(4);
	goster(kok);
	getch();
}
