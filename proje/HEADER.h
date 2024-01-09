#ifndef PROJE_HEADER_H
#define PROJE_HEADER_H

#define ucret 200
#define vergi_yuzde 15
#define prim_yuzde 10
struct calisan {
    char ad[20];
    char soyad[20];
    char makam[40];
    int saat;
    int net_maas;
    int brut_maas;
};
void bilgi_ekle(struct calisan calisanlar [],int *sayi);
void bilgi_guncelle(struct calisan calisanlar[]);
void bilgi_gor(struct calisan calisanlar[]);
void dosyaya_yaz(struct calisan calisanlar[], int sayi);
void dosyadan_oku(struct calisan calisanlar[], int *sayi);
void maas_hesabi(struct calisan calisanlar[],int i);

#endif //PROJE_HEADER_H
