#include <stdio.h>
#include <stdlib.h>
/*1) ��renci bilgilerinden (��renci no, isim, b�l�m) olu�an s�ral� eri�imli bir
dosya olu�turan ve bu dosya i�erisinde isme g�re arama yapan program�
yaz�n�z. Program men� �eklinde haz�rlanmal�d�r. Dosya olu�turma, kay�t
ekleme gibi gerekli t�m fonksiyonlar yaz�lmal�d�r.*/
struct ogrenci{
    int ogrencino;
    char ad[50];
    char bolum[50];
};

 void dosyaolusturma( char dosyaadi[])
 {
     FILE*dosya;
     if((dosya=fopen(dosyaadi,"w"))==NULL)
     {
         printf("dosya olusturulamadi");
     }
     else
     {
         fprintf(dosya,"ogrencino,ad,bolum");
         printf("%s dosyan�z olusturulmustur",dosyaadi);

     }
     fclose(dosya);
 }
 void kayitekleme(char dosyaadi[])
 {
     struct ogrenci yenikayit;
     FILE*dosya;
          if((dosya=fopen(dosyaadi,"a"))==NULL)
          {
              printf("dosya acilmadi");
          }
          else
          {
              printf("lutfen ogrencino,ad ve bolum giriniz");
              printf("?");
              scanf("%d %s %s",&yenikayit.ogrencino,yenikayit.ad,yenikayit.bolum);

              while(!feof(stdin))
              {
                  fprintf("%d%s%s",yenikayit.ogrencino,yenikayit.ad,yenikayit.bolum);
                  printf("?");
            scanf("%d%s%s",&yenikayit.no,yenikayit.ad,yenikayit.bolum);
              }
          }
          fclose(dosya);
 }
    void ismiara(char dosyaadi[],ad[])
    {
        FILE *dosya;
        struct ogrenci isim;
        if((dosya=fopen(dosyaadi,"r"))==NULL)//hi�bir i�lem yok sadece okuma
        {
            printf("dosya acilamadi");
        }
        else
        {
            while(fscanf("%d %s %s",&isim.ogrencino,isim.ad,isim.bolum)!=EOF)// dosyadan okudugu bilgiler bitene kadar devam et
            {
                if(strcmp(isim.ad,ad)==0)
                {
                    printf("%d %s %s",&isim.ogrencino,isim.ad,isim.bolum);
                }
            }
        }
        fclose(dosya);
    }
int main()
{
    char dosyaadi[50];
    char ad[20];

    printf("dosya adini giriniz: ");
    scanf("%s",dosyaadi);

    int secim;
    printf("1. secim: dosya olusturma,\n");
    printf("2. secim: kayit ekleme,\n");
    printf("3. secim: isme gore ara,");
    printf("4. secim: cikis\n");
    printf("secim:  ");
    scanf("%d",&secim);

        while(1)
        {
            switch(secim)
            {
            case 1:
                dosyaolusturma(dosyaadi);
                printf("dosya olusturuldu.\n");
                break;

            case 2:
                kayitekleme(dosyaadi);
                printf("yeni kayit basariyla eklendi...|n");
                break;

            case 3:
                printf("aradiginiz adi girin: ");
                scanf("%s",ad);
                ismiara(dosyaadi,ad);

            case 4:
                printf("cikisiniz yapildi");
                exit(0);
              default:
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
            }
        }















return 0;
}
