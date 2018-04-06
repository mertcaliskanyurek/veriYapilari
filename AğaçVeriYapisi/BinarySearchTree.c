//odev - level level yazdir
//ikili agaci array ile implement edebilir miyiz
#include<stdio.h>
typedef struct tree
{
	int deger;
	int level;
	struct tree *sol,*sag,*ana;
}Agac;
Agac *kok=NULL;
int maxLevel=0;
void ekle(int _sayi)
{
	Agac *yeni;
	yeni=(Agac*)malloc(sizeof(Agac));
	yeni->deger = _sayi;
	yeni->sol = NULL;
	yeni->sag = NULL;
	
	if(kok==NULL)
	{
		kok=yeni;
		kok->level = 1;
		kok->ana=NULL;
	}		
	else
	{
		Agac *gezici = kok,*anne;
		//null bulana kadar gez, anneyi zaten kaydettin 
		//null buldugunda annenin soluna veya sagina koy
		while(gezici!=NULL)
		{
			anne=gezici;
			if(yeni->deger<gezici->deger)
				gezici=gezici->sol;
			else
				gezici=gezici->sag;
		}
		
		if(yeni->deger<anne->deger)
			anne->sol=yeni;
		else
			anne->sag=yeni;
			
		yeni->ana = anne;	
		yeni->level = anne->level+1;
		
		if(yeni->level>maxLevel)
			maxLevel=yeni->level;
	}
}
void ara(int _sayi)
{
	Agac *gezici=kok;
	int sayac=1; //kokte de olabilir o yüzden 1 den basliyoruz
	while(gezici!=NULL && gezici->deger!=_sayi)
	{
		
		if(_sayi<gezici->deger)
			gezici= gezici->sol;
		else
			gezici=gezici->sag;
			
		sayac++;
	}
	
	if(gezici==NULL)
		printf("\nSayi Agacta Bulunamadi\n");
	else
		printf("\nSayi Agacta %d Adimda Bulundu, Anasi : %d\n",sayac,gezici->ana->deger);
	
}
//en kucuk deger agacin en solundadir
//en buyuk deger icin de en saga gidilir
void enKucukDegerBul()
{
	if(kok==NULL)
	{
		printf("Agac Bos..");
		return;
	}
				
	Agac *gezici=kok;
	while(gezici->sol!=NULL)
		gezici=gezici->sol;
	
	printf("\nAgactaki en kucuk deger : %d\n",gezici->deger);
	
}
//kendi kendini cagiracagi icin kok degiskeni alýyor
void gez(Agac *_kok)
{
	if(_kok!=NULL)
	{
		//print fonksyonu ustte olursa preOrder, ortada olursa in order sonda olursa postOrder
		//kucukten buyuge icin in order buyukten kucuge sag-kok-sol
		gez(_kok->sol);
		printf("%d(level : %d),\n",_kok->deger,_kok->level); 
		gez(_kok->sag);
	}
}
int main()
{
	ekle(7); ekle(4); ekle(12); ekle(2); ekle(6); ekle(9); 
	ekle(19); ekle(3); ekle(5); ekle(8); ekle(11); ekle(15); ekle(20);
	gez(kok);
	ara(19);
	enKucukDegerBul();
	printf("\nAgacin maksimum leveli : %d\n",maxLevel);
	system("PAUSE");
	return 0;
}
