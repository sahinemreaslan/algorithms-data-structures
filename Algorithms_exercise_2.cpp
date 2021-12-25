#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int matris_boyutu_bul()
{
	FILE *fp2 = fopen("3.txt","r");
	int karakter=1;
	while(fgetc(fp2)!=EOF)
	{
		karakter++;
	}
	karakter = sqrt(karakter/2);
	fclose(fp2);
	return karakter;
}
int boyut = matris_boyutu_bul();
int sayac = 1;
int **matris,*renk,*prev,*t,*f;
void matris_olustur()
{
	matris = (int **) malloc(boyut*sizeof(int));
    for(int i = 0; i < boyut; i++)
    {
    	matris[i] = (int *) malloc(boyut*sizeof(int));
	}
	renk = (int *) malloc(boyut*sizeof(int));
	prev = (int *) malloc(boyut*sizeof(int));
	t = (int *) malloc(boyut*sizeof(int));
	f = (int *) malloc(boyut*sizeof(int));
}
void Dosyadan_cek()
{
	matris_olustur();
	FILE *fp = fopen("3.txt","r");
	for(int i=0;i<boyut;i++)
	{
		for(int j=0;j<boyut;++j)
		{
			fscanf(fp,"%d",&(matris[i][j]));
		}
	}
	fclose(fp);
}
void gor()
{
	for(int i=0;i<boyut;i++)
	{
		for(int j=0;j<boyut;++j)
		{
			printf("%d",matris[i][j]);
		}
		printf("\n");
	}
}
void Derece_Hesapla(int derece)
{
	int sayac=0,sayac2=0;
	for(int i=0;i<boyut;i++)
	{
		if(matris[i][derece]!=0)
		{
			sayac++;
		}
	}
	for(int j=0;j<boyut;++j)
	{
		if(matris[derece][j]!=0)
		{
			sayac2++;
		}
	}
	printf("Giris Dugumlerin derecesi %d'dir..\nCikis Dugumlerin derecesi %d'dir.\n",sayac,sayac2);
}
int Kenar_Sayisi()
{
	int sayac=0;
	for(int i=0;i<boyut;i++)
	{
		for(int j=0;j<boyut;++j)
		{
			if(matris[i][j]!=0)
			{
				sayac++;
			}
		}
	}
	return sayac;
}
void DFS_Dolas(int dugum)
{
	renk[dugum] = 1;//gri
	t[dugum] = sayac++;
	for(int i=0;i<boyut;i++)
	{
		if(i==dugum)
		{
			continue;
		}
		if(renk[i]==0 && matris[dugum][i]!=0)//baðlantý varsa ve beyazsa
		{
			prev[i] = dugum;//prev[3] = 2;
			DFS_Dolas(i);
		}
	}
	f[dugum] = sayac++;
	renk[dugum] = 2;//siyah
	if(prev[dugum]!=NULL)
	{
		DFS_Dolas(prev[dugum]);
	}
}
void DFS()//i baþlanacak düðümü ifade eder
{
	for(int i=0;i<boyut;i++)
	{
		if(renk[i]==0)
		{
			DFS_Dolas(i);
		}
	}
}
void ilk_Deger()
{
	for(int i=0;i<boyut;i++)
	{
		renk[i] = 0;//0-> beyaz 1 -> gri 2->siyah
		prev[i] = NULL;
	}
}
void menu(int secim)
{
	switch(secim)
	{
		case 1:
			gor();
			break;
		case 2:
			int numara;
			printf("islemin gerceklestirilmesinin istediginiz dugumun numarasini girin: ");
			scanf("%d",&numara);
			Derece_Hesapla(numara);
			break;
		case 3:
			printf("Kenar sayisi %d'dir..\n",Kenar_Sayisi());
			break;
		case 4:
			int dugum;
			printf("Baslangic dugumu '0' yani ilk dugum kabul edilmistir..");
			ilk_Deger();
			DFS();
			printf("\nDugumlerin zamanlari: \n");
			for(int i=0;i<10;i++)
			{
				printf("%d.dugumun = islenme zamani '%d' bulunma zamani '%d'\n",i,t[i],f[i]);
			}
			break;
		case 5:
			system("cls");
			break;
		case 6:
			exit(0);
			break;
		default:
			printf("Yanlis tusladiniz..");
			break;
	}
}
int main ()
{
	Dosyadan_cek();
	while(1)
	{
		printf("Matrisi goruntulemek icin 1'i tuslayiniz..\n");
		printf("istediginiz dugumun Giris ve Cikis dugumlerinin derecesini ogrenmek icin 2'i tuslayiniz..\n");
		printf("Graftaki toplam kenar sayisini ogrenmek icin 3'i tuslayiniz..\n");
		printf("Grafi DFS algoritmasiyla dolasip icin 4'u tuslayiniz..\n");
		printf("Ekrani Temizlemek icin 5'i tuslayiniz..\n");
		printf("Cikis yapmak icin 6'u tuslayiniz..\n");
		int secim;
		scanf("%d",&secim);
		menu(secim);	
	}
	return 0;
}
