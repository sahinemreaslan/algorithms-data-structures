#include <stdio.h>
#include <stdlib.h>
#define Boyut 100
#include <string.h>
typedef struct satir{
	char musteri_adi[100];
	char musteri_soyadi[100];
	int musteri_no;
	int link;
}satir;
int tablo_boyutu;
typedef struct Tablo{
	satir *satirlar=(satir*)malloc(tablo_boyutu*sizeof(satir));
}Tablo;
Tablo tablo;
int key(int musteri_no)// key indeksi doluysa adım adım bir arttır tablo boyutunu geçerse keyi = o a eşitle ikinci defa sona giderse 
{
	return (musteri_no%tablo_boyutu);
}
int tabloda_varmi(int musteri_no)
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		if(tablo.satirlar[i].musteri_no==musteri_no)
		{
			return 1;
		}
	}
	return -1;
}
int link(int musteri_no)//buradan dönecek olan değerin .link'i musteri_nosunun yerlestirileceği indisi gösterimelidir.
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		while(key(tablo.satirlar[i].musteri_no)==key(musteri_no))
		{
			if(tablo.satirlar[i].link==-1)
			{
				return i;
			}
			else
			{
				while(tablo.satirlar[i].link!=-1)
				{
					i = tablo.satirlar[i].link;
				}
				return i;
			}
		}
	}
	return -1;
}
int bosyerbul()
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		if(tablo.satirlar[i].musteri_no==-1)
		{
			return i;
		}
	}
	return -1;
}
int ekle(char musteri_adi[Boyut],char musteri_soyadi[Boyut],int musteri_no)
{
	//0 tablo dolu	//-1 ekleme yapildi //1 tabloda aynı eleman var.
	int anahtar = key(musteri_no);
	if(tabloda_varmi(musteri_no)==1)//tabloda aynı eleman var
	{
		return 1;
	}
	else
	{
		if(tablo.satirlar[anahtar].musteri_no==-1)//indis boş
		{
			strcpy(tablo.satirlar[anahtar].musteri_adi,musteri_adi);
			strcpy(tablo.satirlar[anahtar].musteri_soyadi,musteri_soyadi);
			tablo.satirlar[anahtar].musteri_no = musteri_no;
			return -1;
		}
		else//indis dolu
		{
			if(link(musteri_no)!=-1)//link değeri atanmalı
			{
				if(bosyerbul()!=-1)
				{
					tablo.satirlar[link(musteri_no)].link=bosyerbul();
					strcpy(tablo.satirlar[bosyerbul()].musteri_adi,musteri_adi);
					strcpy(tablo.satirlar[bosyerbul()].musteri_soyadi,musteri_soyadi);
					tablo.satirlar[anahtar].musteri_no = musteri_no;
					return -1;
				}
				else
				{
					return 0;
				}
			}
			else//link değerine gerek yok
			{
				if(bosyerbul()!=-1)
				{
					strcpy(tablo.satirlar[bosyerbul()].musteri_adi,musteri_adi);
					strcpy(tablo.satirlar[bosyerbul()].musteri_soyadi,musteri_soyadi);
					tablo.satirlar[anahtar].musteri_no = musteri_no;
					return -1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
}
int arabul(int aranacak_No)
{
	int anahtar = key(aranacak_No);
	if(tablo.satirlar[anahtar].musteri_no==-1)
	{
		return -1;
	}
	else// iki durum var musteri numarası -1 
	{
		while(tablo.satirlar[anahtar].link!=-1)
		{
			if(tablo.satirlar[anahtar].musteri_no==aranacak_No)
			{
				return 0;
			}
			anahtar = tablo.satirlar[anahtar].link;
		}
	}
	return -1;
}
void listele()
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		if(tablo.satirlar[i].musteri_no==-1)
		{
			continue;
		}
		else
		{
			printf("%s",tablo.satirlar[i].musteri_adi);
			printf(" %s",tablo.satirlar[i].musteri_soyadi);
			printf(" %d",tablo.satirlar[i].musteri_no);
			printf(" %d\n",tablo.satirlar[i].link);
		}
	}
}
void basla()
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		tablo.satirlar[i].musteri_no = -1;
		tablo.satirlar[i].link = -1;
	}
}
void menu()
{
	while(1)
	{
		printf("Hash tablosuna eleman eklemek icin 1'i'\n");
		printf("Hash tablosunda eleman aramak icin 2'yi\n'");
		printf("Hash tablosunu listelemek icin 3'u\n");
		printf("Cikis yapmak icin 4'u tuslayiniz..\n");
		int secim; scanf("%d",&secim);
		fflush(stdin);
		int musteri_no;
		char musteri_adi[100],musteri_soyadi[100];
		switch(secim)
		{
			case 1:
				printf("Musteri adi gir:"); gets(musteri_adi);
				printf("Musteri soy adi gir:"); gets(musteri_soyadi);
				fflush(stdin);
				printf("Musteri numarasi gir:"); scanf("%d",&musteri_no);
				if(ekle(musteri_adi,musteri_soyadi,musteri_no)==-1)
				{
					printf("Ekleme yapildi..\n");
				}
				else if(ekle(musteri_adi,musteri_soyadi,musteri_no)==0)
				{
					printf("Tablo dolu olduğundan ekleme yapilamadi..\n");
				}
				else
				{
					printf("Tabloda ayni eleman olduğundan ekleme yapilamadi...\n");
				}
				menu();
				break;
			case 2:
				printf("Aranacak Musteri nosunu gir: "); scanf("%d",&musteri_no);
				if(arabul(musteri_no)==-1)
				{
					printf("Hash tablosunda oyle bir eleman yok..\n");
				}
				else
				{
					printf("Hash tablosunda %d elemani bulunmaktadir..%d adimda bulunmustur..\n",musteri_no,arabul(musteri_no));
					printf("Adi-Soyadi: %s %s\n",tablo.satirlar[key(musteri_no)].musteri_adi,tablo.satirlar[key(musteri_no)].musteri_soyadi);
				}
				menu();
				break;
			case 3:
				printf("Hash tablosu listeleniyor..\n");
				listele();
				menu();
				break;
			case 4:
				printf("Cikis yapiyorsunuz..");
				exit(0);
				break;
			default:
				printf("Yanlis tusladiniz..");
				printf("Tekrar tuslayiniz..\n");
				menu();
				break;
		}
	}
}
int main()
{
	printf("Tablo boyutu gir: "); scanf("%d",&tablo_boyutu);
	basla();//tablonun bütün elemanlarına -1 gir..
	menu();
	return 0;
}
