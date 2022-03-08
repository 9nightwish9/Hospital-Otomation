#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

///Ahmet Arda Ersöz ///

int yeni = 0;
//struct yapısı 1.1//
typedef struct{
int gun,ay,yil;
}Tarih;
typedef struct{
char isim[30];
char soyisim[30];
char sikayet[100];
int fatura;

Tarih tarih;
}Hasta;
Hasta ** hasta;

//Fonksiyonların tanımlanması pdf 1.1//

void menu();
void ekle();
void listele();
void guncelle();
int fatura();
void ucret();
int sirket();

//main kısmı burada gidilecek fonksiyonlar ayarlanmıştır pdf 1.2//

int main()
{
   int a,b,secim;
    while(1)
    {   printf("********************HASTANE OTOMASYONUNA HOSGELDINIZ***************************");  
	printf("\nnot:-------------------lutfen tum degerleri bitisik yaziniz--------------") ;
        printf("\n******************************\n");
		printf("\n(1)Hasta Ekleme\n******************\n\n");
        printf("(2)Hasta Silme\n******************\n\n");
        printf("(3)Hasta listeleme\n******************\n\n");
        printf("(4)Hasta bilgilerini Guncelleme\n******************\n\n");
        printf("(5)Ucret girme\n******************\n\n ");
        printf("(6)Ucret Listeleme\n******************\n\n ");
        printf("(7)Cikis\n******************\n\n-> ");

        scanf("%d", &secim);
        while(secim < 1 || secim > 7)
            printf("\n->"), scanf("%d", &secim);

        switch(secim)
        {
        case 1:
            ekle(), menu();
            break;
        case 2:
            sil(), menu();
            break;
        case 3:
            listele(), menu();
            break;
        case 4:
            guncelle(), menu();
            break;
        case 5:
            fatura(), menu();
            break;
        case 6:
        	ucret(), menu();
        	break;
        default : system("cls"), printf("-------------------GECMIS OLSUN SAGLIKLI GUNLER DILERIZ-------------------"), getch();
            return 0;
        }
    }
}

// ekle kısmı burda aktarılmıştı pdf 1.3 //

void ekle()
{
	int i;
    system("cls");
    printf("---------------------------------------\n");
    printf("       Hasta Ekleme \n");
    printf("---------------------------------------\n\n");
    int sayi;	
    printf("Kac adet hasta girmek istiyorsunuz ?\n-> ");
    scanf("%d",&sayi);
    if(yeni != 0)
    {
        hasta = realloc(hasta,sizeof(Hasta *) * (yeni + sayi));
    }
    else
    {
        hasta = malloc(sizeof(Hasta *) * sayi);
    }
    for(i = yeni; i < yeni + sayi; i++)
    {
        hasta[i] = malloc(sizeof(Hasta));
        printf("%d. Hastanin Adi: ",i+1);
        scanf("%s",hasta[i]->isim);
        printf("%d. Hastanin soyadi: ",i+1);
        scanf("%s",hasta[i]->soyisim);
        printf("%d. Hastanin yasadigi sorun kisaca(ates,kalp agrisi,mide agrisi vb): ",i+1);
        scanf("%s",hasta[i]->sikayet);
        printf("%d. Hastanin dogdugu gun(sayi ile ): ",i+1);
        scanf("%d",&hasta[i]->tarih.gun);
        printf("%d. hastanin dogdugu ay(sayi ile): ",i+1);
        scanf("%d",&hasta[i]->tarih.ay);
        printf("%d. hastanin dogdugu yil: ",i+1);
        scanf("%d",&hasta[i]->tarih.yil);
    }
    yeni += sayi;
    if(sayi == 1)
        printf("\nHasta Eklendi.\n");
    else
        printf("\nHastalar Eklendi.\n");
}

// menu kısmı burda verilmiştir pdf 1.4 //

void menu()
{
    printf("\nMenuye donmek icin herhangi bir tusa basin");
    getch();
    system("cls");
}

// listele kısmı burda verilmiştir pdf 1.5 //

void listele()
{   int j;
    if(yeni == 0)
        printf("\nHasta bulunmamaktadir.\n");

    else
    {
        for( j = 0; j < yeni; j++)
            printf("\n(%d)Ad: %s\tSoyad: %s\tRahatsizlik: %s\tDogum gunu:%d-%d-%d  ",j+1,hasta[j]->isim,hasta[j]->soyisim,hasta[j]->sikayet,hasta[j]->tarih.gun,hasta[j]->tarih.ay,hasta[j]->tarih.yil);
    }
}

// menu kısmı burda verilmiştir pdf 1.6 //

void sil()
{   int i;
    system("cls");
    int sec;
    printf("-------------------------------------\n");
    printf("        Hasta Silme  Menusu\n");
    printf("-------------------------------------\n\n");
    listele();
    if(yeni != 0)
    {
        printf("\nSilmek istediginiz hastanin numarasini giriniz. Silmekten vazgectiyseniz 0'i tuslayin.\n-> ");
        scanf("%d", &sec);
        while(sec < 0 || sec > yeni)
        {
            printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n-> ");
            scanf("%d", &sec);
        }
        if(sec == 0)
        {
            printf("Hicbir urun silinmedi.");
        }
        else if(sec == yeni)
        {
            hasta = realloc(hasta,sizeof(Hasta *) * (yeni - 1));
            printf("\nHasta silindi.\n");
            yeni--;
        }

        else
        {
            for(i = sec; i < yeni; i++)
            {
                hasta[i-1] = hasta[i];
            }
            hasta = realloc(hasta,sizeof(Hasta*) * (yeni - 1));
            printf("\nHasta  silindi.\n");
            yeni--;
        }

    }
}

// güncelle kısmı burda verilmiştir pdf 1.7 //

void guncelle()
{ int j;
    system("cls");
    printf("------------------------------------\n");
    printf("      Hasta Guncelleme Menusu\n");
    printf("------------------------------------\n\n");

    for( j = 0; j < yeni; j++)
    {
    	
	if(yeni != 0)
    {
        int sec, sec2, kontrol;
        do
        {
            kontrol = 0;
            printf("\nHangi urunu guncellemek istiyorsunuz ?\n-> ");
            scanf("%d", &sec);
            while(sec <= 0 || sec > yeni)
            {
                printf("Yanlis deger girdiniz! Lutfen tekrar giriniz.\n-> ");
                scanf("%d", &sec);
            }
            printf("\n1: Ad\n2: Soyad\n3: sikayet\n4: dogum gunu\n5: dogum ayi\n6 dogum yili Lutfen guncelleme bilgisini secin.\n-> ");
            scanf("%d", &sec2);

            switch(sec2)
            {
            case 1:
                printf("Ad: "), scanf("%s",hasta[sec-1]->isim);
                break;
            case 2:
                printf("Soyad: "), scanf("%s",hasta[sec-1]->soyisim);
                break;
            case 3:
                printf("Tip: "), scanf("%s",hasta[sec-1]->sikayet);
                break;
            case 4:
                printf("Dogum gunu: "), scanf("%d",&hasta[sec-1]->tarih.gun);
                break;
            case 5:
                printf("Dogum ayi: "), scanf("%d",&hasta[sec-1]->tarih.ay);
                break;
            case 6:
			    printf("Dogum yili: "),scanf("%d",&hasta[sec-1]->tarih.yil);    
            default:
                printf("Yanlis deger girdiniz. Lutfen tekrar giriniz.\n"), kontrol = 1;
            }
        }
        while(kontrol == 1);
    printf("\nUrun guncellendi.\n");
    }  
	 }
}

// fatura kısmı burda verilmiştir pdf 1.8 //

int fatura()
{   int j,*k,sigorta,buyukluk;
    system("cls");
    if(yeni == 0)
        printf("\nHasta bulunmamaktadir.\n");
    else 
        {
            for( j = 0; j < yeni; j++)
            {
	            printf("sigortaniz varsa 1 e yoksa 0 a tiklayin ");
                scanf("%d",&sigorta);
                if(sigorta=1)
		        {
	                printf("hastaligin agirlik derecisini seciniz");
	                printf("Ileri duzey ise 1 , orta duzey ise 2 , dusuk duzey ise 3");
	                scanf("%d",&buyukluk);
	                switch(buyukluk)
	                    {
		                case 1: k=2*sirket();  hasta[j]->fatura=k; 
			            case 2: k=1*sirket();  hasta[j]->fatura=k;
			            case 3: k=3*sirket();  hasta[j]->fatura=k;
			            }
		       }
		        else
		        {
			        printf("hastaligin agirlik derecisini seciniz");
	                printf("Ileri duzey ise 1 , orta duzey ise 2 , düsük düzey ise 3");
	                scanf("%d",&buyukluk);
	                switch(buyukluk)
	                    {
				        case 1:  hasta[j]->fatura=10000; 
				        case 2:   hasta[j]->fatura=7000;
				        case 3:  hasta[j]->fatura= 5000;  
				        }
			    }   
            }
        }
}

// sirket kısmı burda verilmiştir pdf 1.9 //

int sirket()
{   
   
   int sigorta;
    printf("sigorta sirketi seciniz");
    printf("\nSemih Sigorta icin 1\n-------------------\nSigartanos Sigorta icin 2 \n---------------\n Sina Sigorta icin 3 \n-----------------\nElitsa sigorta icin 4\n ");
    scanf("%d",sigorta);
        switch(sigorta)
        {
	    case 1:  return 400;
	    case 2:  return 500;
	    case 3:  return 200;
	    case 4:  return 100; 
		}
}

// ucret kısmı burda verilmiştir pdf 1.10 //

void ucret()
{
int j;
    if(yeni == 0)
        printf("\nHasta bulunmamaktadir.\n");

    else
    {
        for( j = 0; j < yeni; j++)
            printf("\n(%d)Ad: %s\tSoyad: %s\tUcret \t fatura : %d  ",j+1,hasta[j]->isim,hasta[j]->soyisim,hasta[j]->fatura);
    }
}




