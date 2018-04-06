#include<stdio.h>
#include<stdlib.h>
typedef struct Dugum{
	int deger;
	struct Dugum *snrki;
	struct Dugum *oncki;
}Dugum;
Dugum *bas=NULL; //Dugum *son=NULL;
void ekle(int deger)
{
    Dugum *yeni = (Dugum*) malloc(sizeof(Dugum));
    yeni->deger = deger;
    yeni->oncki = NULL;
    yeni->snrki = NULL;
    
	if(bas==NULL){
        bas=yeni;
    	//son=yeni;
    	return;
	}
	
	if(bas->deger > deger){
		yeni->snrki= bas;
		bas->oncki = yeni;
		bas = yeni;
		return;
	}
	
	Dugum *temp=bas;
	
	while(temp->snrki!=NULL && temp->snrki->deger < deger){
		//temp->oncki = temp;
		temp = temp->snrki;
	}
		
	if(temp->snrki!=NULL)
		temp->snrki->oncki = yeni;	
		
	yeni->snrki = temp->snrki;	
	temp->snrki = yeni;
	yeni->oncki= temp;
	
		
}
void sil(int deger)
{
	if(bas==NULL){
		printf("Bos\n");
		return;
	}
	
	Dugum *gezici=bas;
	while(gezici->deger!=deger && gezici->snrki!=NULL)
		gezici=gezici->snrki;
		
	if(gezici->snrki==NULL)
		printf("Bulunamadi .\n");
	else{
		gezici->oncki->snrki = gezici->snrki;
		gezici->snrki->oncki = gezici->oncki;
		free(gezici);
		printf("\n%d silindi.\n",deger);
	}

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
	ekle(7);
	ekle(8);
	ekle(9);
	ekle(11);
	ekle(10);
	goster();
	//sil(1);
	return 0;
}
