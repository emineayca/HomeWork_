#include <stdio.h>

struct ders {
    int ders_kod;
    int vize;
    int final;
    double gecmenotu;
};

struct sahis_bilgileri {
    char ad[40];
    char soyad[40];
    int No;
    struct ders dersler[5];
};

void ogrenciBilgileriAl(struct sahis_bilgileri *ogrenci) {
    printf("Ogrenci adi: ");
    scanf("%s", ogrenci->ad);

    printf("Ogrenci soyadi: ");
    scanf("%s", ogrenci->soyad);

    printf("Ogrenci No: ");
    scanf("%d", &ogrenci->No);

    for (int i = 0; i < 5; ++i) {
        printf("Ders kodu: ");
        scanf("%d", &ogrenci->dersler[i].ders_kod);

        printf("Vize notu: ");
        scanf("%d", &ogrenci->dersler[i].vize);

        printf("Final notu: ");
        scanf("%d", &ogrenci->dersler[i].final);

        
        ogrenci->dersler[i].gecmenotu = 0.4 * ogrenci->dersler[i].vize + 0.6 * ogrenci->dersler[i].final;
    }
}

void ogrenciBilgileriYazdir(struct sahis_bilgileri ogrenci) {
    printf("\nOgrenci Bilgileri:\n");
    printf("Ad: %s\n", ogrenci.ad);
    printf("Soyad: %s\n", ogrenci.soyad);
    printf("No: %d\n", ogrenci.No);

    for (int i = 0; i < 5; ++i) {
        printf("Ders Kodu: %d\n", ogrenci.dersler[i].ders_kod);
        printf("Vize: %d\n", ogrenci.dersler[i].vize);
        printf("Final: %d\n", ogrenci.dersler[i].final);
        printf("Gecme Notu: %.2lf\n", ogrenci.dersler[i].gecmenotu);
        printf("-----------------\n");
    }
}

int main() {
    struct sahis_bilgileri ogrenciler[5];

    for (int i = 0; i < 5; ++i) {
        ogrenciBilgileriAl(&ogrenciler[i]);
    }

    for (int i = 0; i < 5; ++i) {
        ogrenciBilgileriYazdir(ogrenciler[i]);
    }

    return 0;
}

