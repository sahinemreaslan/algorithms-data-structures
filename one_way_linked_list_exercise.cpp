#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct list 
{
    int frekans;
    char harf;
    struct list *sonraki;
}liste;
liste *ilk, *son, *kutu, *gecici;
int listedevarmi(char harf)//1 döndürürse listede var 0 döndürürse listede yok
{
	gecici = ilk;
	if(gecici==NULL)
	{
		return 0;//listede o harf yok
	}
	while(gecici->harf!=harf)
	{
		if(gecici->sonraki==NULL)
		{
			gecici = ilk;
			return 0;//listede o harf yok
		}
		gecici = gecici->sonraki;
	}
	gecici = ilk;
	return 1;//listede o harf var
}
void sirala(liste *gecici,liste *gecici1,liste *yaz)//bubble sort algoritmasýyla sýralama
{
	int temp;
	for(gecici=yaz;gecici->sonraki!=NULL;gecici=gecici->sonraki)
	{
		for(gecici1=yaz;gecici1->sonraki!=NULL;gecici1=gecici1->sonraki)
		{
			if(gecici1->harf>gecici->harf)
			{
			temp=gecici1->harf;
			gecici1->harf=gecici->harf;
			gecici->harf=temp;
			}
		}
	}
}
void ekle(liste *kutu)
{
	if(ilk == NULL)//liste boþsa ekleniyor
	{
		ilk = kutu;
		gecici = ilk;
		son = kutu;
        son->sonraki = NULL;
    }
    else//hep baþa ekleniyor
    {
		ilk = kutu;
		ilk -> sonraki = gecici;
		gecici = ilk;
	}
	sirala(ilk,ilk,ilk);//ekledikten hemen sonra siralama fonksiyonuna ilk yollanýyor.
}
void listele()//listeleme fonksiyonu
{
	if(ilk==NULL)
	{
		printf("liste bos");
	}
	else
	{
		while(gecici->sonraki!=NULL)
		{
		printf("%d",gecici->frekans);
		printf("%c\n",gecici->harf);
		gecici = gecici -> sonraki;
		}
		gecici = ilk;
	}
}
int main()
{
	int harf, frekans, secim;
	while(1)
	{
		printf("Secim: 1-Listeye ekle\n2-Yazdir\n3-Cikis");
		scanf("%d",&secim);
		fflush(stdin);
		switch(secim)
		{
			case 1 :
				printf("Harf giriniz: "); scanf("%c",&harf);
				fflush(stdin);
				if(listedevarmi(harf)==0)
				{
					printf("Frekans giriniz: "); scanf("%d",&frekans);
					fflush(stdin);
					kutu = (liste*) malloc(sizeof(liste));
        			kutu->frekans = frekans;
        			kutu->harf = harf;
        			ekle(kutu);
				}
				else
				{
					printf("Listede olmayan harf giriniz: ");
				}
				break;
			case 2 :
				listele();
				break;
			case 3 :
				exit(0);	
				break;
		}
	}
	return 0;
}
