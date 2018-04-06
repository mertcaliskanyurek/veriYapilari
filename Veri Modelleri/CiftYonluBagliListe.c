#include<stdio.h>
#include<stdlib.h>
typedef struct Dugum{
	int deger;
	struct Dugum *snrki;
	struct Dugum *oncki;
}Dugum;
Dugum *bas=NULL; Dugum *son=NULL;

void ekle(int deger)
{
    Dugum *yeni = (Dugum*) malloc(sizeof(Dugum));
    yeni->deger = deger;
    yeni->oncki = NULL;
    yeni->snrki = NULL;
    
	if(bas==NULL){
        bas=yeni;
    	son=yeni;
    	return;
	}
	
	if(bas==son){
		bas->snrki=yeni;
		yeni->oncki = bas;
		son=yeni;
		return;
	}
	
	son->snrki=yeni;
	yeni->oncki = son;
	son=yeni;
	
}
void sil(int deger)
{
	if(bas==NULL){
		printf("Bos\n");
		return;
	}
	
	Dugum *gezici=son;
	while(gezici->deger!=deger && gezici!=NULL)
		gezici=gezici->oncki;
		
	if(gezici==NULL)
		printf("Bulunamadi .\n");
	else{
		gezici->oncki->snrki = gezici->snrki;
		gezici->snrki->oncki = gezici->oncki;
		free(gezici);
		printf("\n%d silindi.\n",deger);
	}
	
	goster();
}
void goster()
{
	if(bas==NULL){
		printf("Bos\n");
		return;
	}
	
	Dugum *gezici=bas;
	while(gezici!=NULL)
	{
		printf("%d, ",gezici->deger);
		gezici=gezici->snrki;
	}
}
main(){
	ekle(5);
	ekle(6);
	ekle(8);
	ekle(1);
	ekle(3);
	goster();
	sil(1);
	return 0;
}
