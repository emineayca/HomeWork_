//ikinci k�s�m 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tablo_boyutu adet
int adet = 5;
typedef struct Liste {
	int index;
	int link;
	int musteri_numarasi;
	char musteri_ad[100];
	char musteri_soyad[100];
} Row;

typedef struct tablo {
	Row satirlar[];
} Tablo;

Tablo Tablolar;

void initialize() { //Olu�turulan listeye -1 de�erlerini atad�m
	for(int i = 0; i < tablo_boyutu; i++){
	    Tablolar.satirlar[i].index = -1;
		Tablolar.satirlar[i].musteri_numarasi = -1;
		Tablolar.satirlar[i].link = -1;
	}
}

int hash(int numara){ //Mod ��lemini yapt���m fonksiyon
	return (numara % tablo_boyutu);
}

void ekle(int musteri_numarasi, char * musteri_ad, char * musteri_soyad) { 
	int adres = hash(musteri_numarasi), gecici = adres; //adres de�i�kenine m��teri numaras�n�n modunu al�p atad�m.
	if(Tablolar.satirlar[adres].index == -1){ //e�er listedeki index bo�sa(-1 ise) fonksiyona parametre olarak gelen de�erleri atad�m.
		Tablolar.satirlar[adres].index=adres;
		Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
		strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
		strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
	}
	else {
		int gecici_boyut = 0, gecici_boyut2 = 0;
		adres = 0;
		while(gecici_boyut != tablo_boyutu){ //s�r�dan ba�lat�p t�m listeyi gezen while d�ng�s�
			if(Tablolar.satirlar[adres].index == -1){ //0. indexteki bo�sa parametre olarak gelenleri e�itliyorum.
				Tablolar.satirlar[adres].index = adres;
				Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
				strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
				strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
				if(Tablolar.satirlar[gecici].link == -1){ //E�er listenin linki bo�sa gecicideki linke o an adresteki linki at�yorum.
					Tablolar.satirlar[gecici].link = Tablolar.satirlar[adres].index;
					return;
				}
				else { 
					while(gecici_boyut2 != tablo_boyutu - 1){
						if(hash(Tablolar.satirlar[gecici_boyut2].musteri_numarasi) == gecici && Tablolar.satirlar[gecici_boyut2].link == -1){ //gecici olarak yeniden atad���m 0 de�erindeki m��teri numaras�n� hash fonksiyonuna g�nderdim. d�nen de�er ile o indexteki link bo�sa ona ba�lad�m.
							Tablolar.satirlar[gecici_boyut2].link = Tablolar.satirlar[adres].index;
							printf("Tum Musteriler Basariyla Eklendi!\n");
							return;
						}
						gecici_boyut2++;
					}
					printf("Hata Olustu! Musteri Eklenemedi!\n");						
				}				
				return;
			}
			adres++;
			gecici_boyut++;
		}
		printf("Tablo Dolu!\n");
		return;
	}
}

int ara(int musteri_numarasi){
	int adres = hash(musteri_numarasi), gecici = adres, sayac = 0;
	if(Tablolar.satirlar[adres].musteri_numarasi == musteri_numarasi){ //E�er arad���m�z de�er ilk listede yani direk bulabiliyorsak buras� �al���yor.
		printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, ++sayac);
		return 0;
	}
	else {	
		int gecici_boyut = 0;
		while(gecici_boyut != tablo_boyutu){
			sayac++;
			if(Tablolar.satirlar[Tablolar.satirlar[adres].link].musteri_numarasi == musteri_numarasi){ //e�er linke g�re arama yapmak gerekirse buras� �al���yor. adresteki linke bak�p gelen de�er ayn� m� diye kontrol ediyor. de�ilse di�er adrese y�kseltiyorum.
				printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, sayac);
				return 0;
			}
			if(hash(Tablolar.satirlar[gecici_boyut].musteri_numarasi) == gecici){ //linke g�re arama yapt���m�zda �nceki linki takip edebilmek i�in adresi g�ncelliyorum.
				adres = gecici_boyut;
			}
			gecici_boyut++;
		}
		printf("Aradiginiz Musteri Bulunamadi!\n");
		return -1;
	}
}

void listele(){
	printf("Index\tNumara\tAdi\tSoyadi\tLink\n");
	printf("--------------------------------------\n");
 	for(int i = 0; i < tablo_boyutu; i++){
		printf("%d \t", i);
		printf("%d \t", Tablolar.satirlar[i].musteri_numarasi);
		printf("%s \t", Tablolar.satirlar[i].musteri_ad);
		printf("%s \t", Tablolar.satirlar[i].musteri_soyad);
		printf("%d \t", Tablolar.satirlar[i].link); 			
		printf("\n");
	}
}

int main(){
	printf("Uygulama 2\n");
	printf("Tablo Boyutu Giriniz: ");
	scanf("%d", &adet);
	tablo_boyutu = adet;
	initialize();
	ekle(10, "faruk", "ipek");
	ekle(13, "tarik", "cakir");
	ekle(23, "ahmet", "yilmaz");
	ekle(18, "kemal", "demir");
	ekle(12, "aa","a");
	ekle(20,"GF","GG");
	printf("--------------------------------------\n");
	listele();
	printf("--------------------------------------\n");
	ara(18);
	ara(12);
}
