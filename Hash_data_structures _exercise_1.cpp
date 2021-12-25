#include <stdio.h>
#include <stdlib.h>
#define Boyut 100
typedef struct satir{
	char musteri_adi[100];
	char musteri_soyadi[100];
	int musteri_no;
}satir;
int tablo_boyutu;
typedef struct Tablo{
	satir *satirlar=(satir*)malloc(tablo_boyutu*sizeof(satir));
}Tablo;
Tablo tablo;
int key(int musteri_no)//hash_index belirleniyor 
{
	return (musteri_no%tablo_boyutu);
}
int ekle(char musteri_adi[Boyut],char musteri_soyadi[Boyut],int musteri_no)
{
	int anahtar = key(musteri_no);//hash_index belirleniyor 
	if(tablo.satirlar[anahtar].musteri_no==-1)//index boþsa ekleme yapýlýyor..
	{
		for(int i=0;i<musteri_adi[i]!=NULL;i++)
		{
			tablo.satirlar[anahtar].musteri_soyadi[i] = musteri_soyadi[i];
		}
		for(int i=0;i<musteri_soyadi[i]!=NULL;i++)
		{
			tablo.satirlar[anahtar].musteri_adi[i] = musteri_adi[i];
		}
		tablo.satirlar[anahtar].musteri_no = musteri_no;
		return -1;
	}
	else if(tablo.satirlar[anahtar].musteri_no==musteri_no)//index dolu ve ayný eleman eklenmeye calisiliyorsa ekleme yapýlmýyor..
	{
			return 1;
	}
	else//index dolu ve farklý bir eleman varsa
	{
		int tut = anahtar;
		int sayac2=0;
		while(anahtar<tablo_boyutu)//boþ yer bulana kadar ilerleme yapiyor
		{
			if(anahtar==tut-1 || anahtar==tablo_boyutu-1)//sona gelindiðinde baþa dönmek için yapý
			{
				anahtar = -1;
				sayac2++;
				if(sayac2==2)
				{
					return 0;
				}
			}
			anahtar = anahtar + 1;//anahtari her adimda arttiriyor
			if(tablo.satirlar[anahtar].musteri_no==-1)//index boþsa ekleme yapýlýyor..
			{
				for(int i=0;i<musteri_adi[i]!=NULL;i++)
				{
					tablo.satirlar[i].musteri_soyadi[i] = musteri_soyadi[i];
				}
				for(int i=0;i<musteri_soyadi[i]!=NULL;i++)
				{
					tablo.satirlar[i].musteri_adi[i] = musteri_adi[i];
				}
				tablo.satirlar[anahtar].musteri_no = musteri_no;
				return -1;
			}
			else
			{
				if(tablo.satirlar[anahtar].musteri_no==musteri_no)//index dolu ve ayný eleman eklenmeye calisiliyorsa ekleme yapýlmýyor.
				{
					return 1;
				}
				else
				{
					continue;
				}
			}
		}
	}
}
int arabul(int aranacak_No)
{
	int anahtar = key(aranacak_No);//aranacak indis
	int sayac=1;
	if(tablo.satirlar[anahtar].musteri_no==-1)//hash_indexinin olduðu yer boþsa eleman yoktur
	{
		return -1;
	}
	else//hash index doluysa
	{
		while(tablo.satirlar[anahtar].musteri_no!=-1 && sayac < tablo_boyutu )//o index dýþýnda diðer indexlerde var mý diye bakýlýyor
		{
			if(tablo.satirlar[anahtar].musteri_no==aranacak_No)
			{
				return sayac;
			}
			anahtar++;
			sayac++;
		}
		return -1;//eðer ki döngü içerisinde eleman bulunmadýysa demek ki öyle bir eleman yoktur
	}
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
			printf("\t%s",tablo.satirlar[i].musteri_soyadi);
			printf("\t%d\n",tablo.satirlar[i].musteri_no);
		}
	}
}
void basla()
{
	for(int i=0;i<tablo_boyutu;i++)
	{
		tablo.satirlar[i].musteri_no = -1;
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
					printf("Tablo dolu olduðundan ekleme yapilamadi..\n");
				}
				else
				{
					printf("Tabloda ayni eleman olduðundan ekleme yapilamadi...\n");
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
	basla();//tablonun bütün elemanlarýna -1 gir..
	menu();
	return 0;
}
