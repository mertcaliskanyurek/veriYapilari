#include<stdio.h>
#include<stdlib.h>
typedef struct Veri{
	short int veri;
	struct Veri *sonraki; 
}Veri;
Veri *bas=NULL;
void BasaEkle(short int _veri)
{
	Veri *yeni =(Veri*) malloc(sizeof(Veri));
	yeni->veri = _veri;
	//liste bos ise
	if(bas==NULL)
	{
		bas=yeni;
		bas->sonraki = NULL;
	}
	else
	{
		yeni->sonraki = bas;
		bas = yeni;
	}
}
void SonaEkle(short int _veri)
{
	Veri *yeni = (Veri*) malloc(sizeof(Veri));
	yeni->veri = _veri;
	yeni->sonraki = NULL;
	if(bas==NULL)
		bas=yeni;
	else
	{
		Veri *dugum=bas;
		while(dugum->sonraki!=NULL)
			dugum = dugum->sonraki;
			
		dugum->sonraki = yeni;
	}
}
void BastanCikar()
{
	if(bas==NULL) printf("Vallaha cýkarmam..\n");
	else
	{
		Veri *temp=bas;
		bas=bas->sonraki;
		free(temp);
	}
}
void SondanCikar()
{
	if(bas==NULL) 
		printf("Vallaha cýkarmam..\n");
	else if(bas->sonraki==NULL)
		bas=NULL;
	else
	{
		Veri *dugum=bas,*oncekiDugum=bas;
		while(dugum->sonraki!=NULL)
		{
			oncekiDugum = dugum;
			dugum = dugum->sonraki;
		}
		printf("%d cikarildi.\n",dugum->veri);
		oncekiDugum->sonraki = NULL;
		free(dugum);
	}
}
void Goster()
{
	Veri *dugum=bas;
	if(bas==NULL)
		printf("liste bos...\n");
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
	//BasaEkle(12);BasaEkle(44); BasaEkle(8);
	SonaEkle(88); //SonaEkle(82); SonaEkle(85);
	//BastanCikar();
	SondanCikar();
	Goster();
}
