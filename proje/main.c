#include <stdio.h>
#include "HEADER.h"
#include "FONKSİYON.c"

int main() {
    int sayi=0;
    int no;
    struct calisan calisanlar[3000];

    dosyadan_oku(calisanlar, &sayi);

    do {
        printf("\n\tCALISAN MAAS SISTEMI\n");
        printf("1-Yeni Calisan Bilgisi Ekle \n2-Calisan Bilgisi Guncelle \n3-Calisan Bilgisi Gor \n0-Cikis( DOSYAYA KAYDET)\n ");
        printf("Yapilacak Islemi Seciniz=>");
        scanf("%d",&no);

        switch (no) {
            case 0:
                dosyaya_yaz(calisanlar,sayi);
                break;
            case 1:
                bilgi_ekle(calisanlar, &sayi);
                break;
            case 2:
                bilgi_guncelle(calisanlar);
                break;
            case 3:
                bilgi_gor(calisanlar);
                break;
            default:
                printf("Gecersiz islem yapildi.\nYapilacak islemi tekrar seciniz.");
        }
    }while(no != 0);

    return 0;
}

