#include "HEADER.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void dosyaya_yaz(struct calisan calisanlar[], int sayi) {
    FILE *dosya ;
    dosya= fopen("calisan_bil.txt", "a");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya acilamadi! Hata Kodu: %d\n", errno);
        perror("Hata Mesaji");
        return;
    }

    for (int i = 0; i < sayi; i++) {
        fprintf(dosya, "%s %s %s %d %d %d\n", calisanlar[i].ad, calisanlar[i].soyad, calisanlar[i].makam,
                calisanlar[i].saat, calisanlar[i].net_maas,calisanlar[i].brut_maas);
    }

    fclose(dosya);
}

void dosyadan_oku(struct calisan calisanlar[], int *sayi) {
    FILE *dosya ;
    dosya= fopen("calisan_bil.txt", "r");

    if (dosya == NULL) {
        fprintf(stderr, "Dosya acilamadi! Hata Kodu: %d\n", errno);
        perror("Hata Mesaji");
        return;
    }

    while (fscanf(dosya, "%s %s %s %d %d %d", calisanlar[*sayi].ad, calisanlar[*sayi].soyad,
                  calisanlar[*sayi].makam, &calisanlar[*sayi].saat, &calisanlar[*sayi].net_maas,&calisanlar[*sayi].brut_maas) == 5) {
        (*sayi)++;
    }

    fclose(dosya);
}

void maas_hesabi(struct calisan calisanlar[],int i){
    int net,brut,vergi,prim;
    brut=calisanlar[i].saat*ucret;
    vergi=brut*vergi_yuzde/100;
    prim=brut*prim_yuzde/100;
    net=brut+prim-vergi;
    calisanlar[i].brut_maas=brut;
    calisanlar[i].net_maas=net;
}

void bilgi_ekle(struct calisan calisanlar[],int *sayi){
    if(*sayi<=3000){
        printf("\nCalisanin Ismi(bir kelimelik)=");
        scanf("%s",calisanlar[*sayi].ad);

        printf("\nCalisanin Soyismi=");
        scanf("%s",calisanlar[*sayi].soyad);

        printf("\nCalisanin Makami=");
        scanf("%s",calisanlar[*sayi].makam);

        printf("\nCalisanin Aylik Calistigi Saat Sayisi=");
        scanf("%d",&calisanlar[*sayi].saat);
        maas_hesabi(calisanlar,*sayi);

        printf("\n Calisanin Bu Ay Net Maasi %d TL,Brut Maasi %d TL",calisanlar[*sayi].net_maas,calisanlar[*sayi].brut_maas);

        printf("\n%d numarali calisan olarak kaydedildi.\n",*sayi);
        (*sayi)++;
    }
    else{
        printf("\nSistemde yeterli kayıt alanı bulunmamaktadir!");
    }
}

void bilgi_guncelle(struct calisan calisanlar[]){
    int i;
    int secim;
    char yeniS[40];
    int yeniD;
    char eh;
    while(1) {
        printf("\nGuncellemek istediginiz calisanin nosunu giriniz:");
        scanf("%d", &i);
        printf("\tHangi bilgiyi guncellemek istiyorsunuz.Secin.\n");
        printf("1-Ad\n2-soyad\n3-saat\n4-makam\n");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("Yeni isim bilgisini giriniz");
                scanf("%s", yeniS);
                strcpy(calisanlar[i].ad ,yeniS);
                printf("Islem basariyla tamamlandi!");
                break;
            case 2:
                printf("Yeni soyisim bilgisini giriniz");
                scanf("%s", yeniS);
                strcpy(calisanlar[i].soyad ,yeniS);
                printf("Islem basariyla tamamlandi!");
                break;
            case 3:
                printf("Yeni calisilan saat bilgisini giriniz");
                scanf("%d", &yeniD);
                calisanlar[i].saat = yeniD;
                printf("Islem basariyla tamamlandi!");
                maas_hesabi(calisanlar,i);
                break;
            case 4:
                printf("Yeni makam bilgisini giriniz");
                scanf("%s",yeniS);
                strcpy(calisanlar[i].makam ,yeniS);
                printf("Islem basariyla tamamlandi!");
                break;
            default:
                printf("GECERSİZ İSLEM!");

        }
        printf("\nYeni bir guncelleme daha yapmak istiyor musunuz?(E/H)");
        scanf(" %c", &eh);
        if(eh=='H' || eh=='h')
            break;
        if(eh=='E' || eh=='e')
            printf("----------------------------------------------------");
        else {
            printf("GECERSIZ ISLEM! ");
            break;
        }


    }
}

void bilgi_gor(struct calisan calisanlar[]){
    int i;
    char eh;
    while(1){
        printf("\nBilgilerini Gormek Istediginiz Calisanin Nosunu Giriniz");
        scanf("%d",&i);
        if(i>=0 && i<3000)
            printf("\nADI=%s \nSOYADI=%s \nMAKAMI=%s \nCALISTIGI SAAT=%d \nNET MAASI=%d \nBRUT MAASI=%d",calisanlar[i].ad,calisanlar[i].soyad,calisanlar[i].makam,calisanlar[i].saat,calisanlar[i].net_maas,calisanlar[i].brut_maas);
        else {
            printf("GECERSIZ ISLEM!");
            break;
        }

        printf("\nYeni bir bilgi goruntuleme daha yapmak istiyor musunuz?(E/H)");
        scanf(" %c", &eh);
        if(eh=='H' || eh=='h')
            break;
        if(eh=='E' || eh=='e')
            printf("----------------------------------------------------");
        else {
            printf("GECERSIZ ISLEM! ");
            break;
        }
    }

}

