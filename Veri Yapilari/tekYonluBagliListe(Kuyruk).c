#include<stdio.h>
#include<stdlib.h>
typedef struct Dugum{
	short int veri;
	struct Dugum *sonraki; 
}Dugum;
Dugum *bas=NULL,*son=NULL;
void Ekle(short int _veri)
{
	Dugum *yeni = (Dugum*) malloc(sizeof(Dugum));
	yeni->veri= _veri;
	yeni->sonraki = NULL;
	
	if(bas==NULL)
	{
		bas=yeni;
		son=yeni;
	}
	else
	{
	
		son->sonraki = yeni;
		son = yeni;
	}	

}
void Cikar()
{
	if(bas==NULL)
		printf("Valla Cikarmam");
	else
	{
		Dugum *temp=bas;
		bas = bas->sonraki;
	}
}
void Ara(short int _veri)
{
	Dugum *gezici=bas;
	int kacAdimda=0;
	if(bas==NULL)
		printf("Neyi Arican");
	else
		while(gezici!=NULL && gezici->veri!=_veri)
		{
			kacAdimda++;
			gezici = gezici->sonraki;
		}
	if(gezici==NULL)
		printf("Bulamadik\n");
	else
		printf("%d adimda bulduk\n",kacAdimda);
}
void Sil(short int _veri)
{
	Dugum *gezici=bas;
	Dugum *oncekiGez=bas;
	if(bas==NULL)
		printf("Neyi Silcen\n");
	else if(bas->veri == _veri)
		Cikar();
	else
	{
		while(gezici!= NULL && gezici->veri!=_veri)
		{
			oncekiGez = gezici;
			gezici = gezici->sonraki;
		}
		
		if(gezici==NULL)
			printf("Bulamadik\n");
			
		else if(gezici == son)
		{
			oncekiGez->sonraki = NULL;
			son=oncekiGez;
			printf("%d siliniyor...\n",gezici->veri);
			free(gezici);
		}
		else
		{
			oncekiGez->sonraki = gezici->sonraki;
			printf("%d siliniyor...\n",gezici->veri);
			free(gezici);
		}
			
	}
}
void Goster()
{
	Dugum *dugum=bas;
	if(bas==NULL)
		printf("liste bos...\n");
	else if(bas==son)	
		bas=NULL; 
	else
	{
		while(dugum!=NULL)
		{
			printf("%d,",dugum->veri);
			dugum = dugum->sonraki;
		}
	}
}
main()
{
	Ekle(88); Ekle(99); Ekle(56); Ekle(32);Ekle(47);// Cikar();Cikar();Cikar();
	Sil(99);
	Goster();
}
