//birinci kýsým
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define tablo_boyutu adet
int adet = 5;
typedef struct Liste {
	int index;
	int musteri_numarasi;
	char musteri_ad[100];
	char musteri_soyad[100];
	struct Liste * sonraki;
} Row;

typedef struct Tablo {
	Row satirlar[];
} Tablo;

Tablo Tablolar;

void initialise() { //Oluþturulan listeye -1 deðerlerini atýyorum
	for(int i = 0; i < tablo_boyutu; i++) {
		Tablolar.satirlar[i].musteri_numarasi = -1;
		Tablolar.satirlar[i].index = -1;
		Tablolar.satirlar[i].musteri_numarasi = -1;
		Tablolar.satirlar[i].sonraki = NULL;
	}
}
int Hash(int numara) { //Mod Ýþlemini yaptýðým fonksiyon
	return (numara % tablo_boyutu);
}


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

void initialize() { //Oluþturulan listeye -1 deðerlerini atadým
	for(int i = 0; i < tablo_boyutu; i++){
	    Tablolar.satirlar[i].index = -1;
		Tablolar.satirlar[i].musteri_numarasi = -1;
		Tablolar.satirlar[i].link = -1;
	}
}

int hash(int numara){ //Mod Ýþlemini yaptýðým fonksiyon
	return (numara % tablo_boyutu);
}

void ekle(int musteri_numarasi, char * musteri_ad, char * musteri_soyad) { 
	int adres = hash(musteri_numarasi), gecici = adres; //adres deðiþkenine müþteri numarasýnýn modunu alýp atadým.
	if(Tablolar.satirlar[adres].index == -1){ //eðer listedeki index boþsa(-1 ise) fonksiyona parametre olarak gelen deðerleri atadým.
		Tablolar.satirlar[adres].index=adres;
		Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
		strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
		strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
	}
	else {
		int gecici_boyut = 0, gecici_boyut2 = 0;
		adres = 0;
		while(gecici_boyut != tablo_boyutu){ //sýrýdan baþlatýp tüm listeyi gezen while döngüsü
			if(Tablolar.satirlar[adres].index == -1){ //0. indexteki boþsa parametre olarak gelenleri eþitliyorum.
				Tablolar.satirlar[adres].index = adres;
				Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
				strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
				strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
				if(Tablolar.satirlar[gecici].link == -1){ //Eðer listenin linki boþsa gecicideki linke o an adresteki linki atýyorum.
					Tablolar.satirlar[gecici].link = Tablolar.satirlar[adres].index;
					return;
				}
				else { 
					while(gecici_boyut2 != tablo_boyutu - 1){
						if(hash(Tablolar.satirlar[gecici_boyut2].musteri_numarasi) == gecici && Tablolar.satirlar[gecici_boyut2].link == -1){ //gecici olarak yeniden atadýðým 0 deðerindeki müþteri numarasýný hash fonksiyonuna gönderdim. dönen deðer ile o indexteki link boþsa ona baðladým.
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
	if(Tablolar.satirlar[adres].musteri_numarasi == musteri_numarasi){ //Eðer aradýðýmýz deðer ilk listede yani direk bulabiliyorsak burasý çalýþýyor.
		printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, ++sayac);
		return 0;
	}
	else {	
		int gecici_boyut = 0;
		while(gecici_boyut != tablo_boyutu){
			sayac++;
			if(Tablolar.satirlar[Tablolar.satirlar[adres].link].musteri_numarasi == musteri_numarasi){ //eðer linke göre arama yapmak gerekirse burasý çalýþýyor. adresteki linke bakýp gelen deðer ayný mý diye kontrol ediyor. deðilse diðer adrese yükseltiyorum.
				printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, sayac);
				return 0;
			}
			if(hash(Tablolar.satirlar[gecici_boyut].musteri_numarasi) == gecici){ //linke göre arama yaptýðýmýzda önceki linki takip edebilmek için adresi güncelliyorum.
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




void ekle(int musteri_numarasi, char * musteri_ad, char * musteri_soyad) {
	int adres = Hash(musteri_numarasi), gecici_boyut = 0; //adres deðiþkenine müþteri numarasýnýn modunu alýp atadým.
	if(Tablolar.satirlar[adres].index == -1) { //eðer listedeki index boþsa(-1 ise) fonksiyona parametre olarak gelen deðerleri atadým.
		Tablolar.satirlar[adres].index = adres;
		Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
		strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
		strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
	}
	else {
		while(gecici_boyut!=tablo_boyutu){
			if(adres==tablo_boyutu){ //eðer adres ile tablo boyutu eþit olursa adresi baþta sabitliyorum.
			   adres=0;
			}	
			else if(Tablolar.satirlar[adres].index == -1){ //eðer adres sýfýrda deðilse parametre olarka gelenleri eklesin					
				Tablolar.satirlar[adres].index = adres;
				Tablolar.satirlar[adres].musteri_numarasi = musteri_numarasi;
				strcpy(Tablolar.satirlar[adres].musteri_ad, musteri_ad);
				strcpy(Tablolar.satirlar[adres].musteri_soyad, musteri_soyad);
				return;
			}
			else {//adresi bir artýyorum
				adres++;
			}	
			gecici_boyut++;		
		}
		printf("Tablo Dolu!\n");
	}
}

int ara(int musteri_numarasi) {
	int adres = Hash(musteri_numarasi);
	int sayac = 0;
	if(Tablolar.satirlar[adres].musteri_numarasi==musteri_numarasi) { //Eðer aradýðýmýz deðer ilk listede yani direk bulabiliyorsak burasý çalýþýyor.
		printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, ++sayac);
		return 0;
	}
	else {
		int gecici_boyut = 0;
		while(gecici_boyut != tablo_boyutu) { //tüm tabloyu tarýyorum
			sayac++;
			if(adres == tablo_boyutu - 1){
			   adres = 0;
			}
			else if(Tablolar.satirlar[adres].musteri_numarasi == musteri_numarasi){ //eðer baþarýlý bir arama iþlemi yaparsa burasý çalýþýyor. 
				printf("%d Numarali Musteri %d Adimda Bulundu!\n", musteri_numarasi, sayac);
				return 0;
			}
			else adres++; //tabloda gezmesi için artýrýyorum.
		}
		printf("Aradiginiz Musteri Bulunamadi!\n");
		return -1;
	}
}

void listele() {
	printf("Index\tNumara\tAdi\tSoyadi\n");
	printf("--------------------------------------\n");
	for(int i = 0; i < tablo_boyutu; i++){
		printf("%d \t", i);
		printf("%d \t", Tablolar.satirlar[i].musteri_numarasi);
		printf("%s \t", Tablolar.satirlar[i].musteri_ad);
		printf("%s \t", Tablolar.satirlar[i].musteri_soyad);
		printf("\n");
	}
}

int main() {
	printf("Uygulama 1\n");
	printf("Tablo Boyutu Giriniz: ");
	scanf("%d", &adet);
	tablo_boyutu = adet;
	initialise();
	ekle(10, "faruk", "ipek");
	ekle(13, "tarik", "cakir");
	ekle(23, "ahmet", "yilmaz");
	ekle(18, "kemal", "demir");
	printf("--------------------------------------\n");
	listele();
	printf("--------------------------------------\n");
	ara(18);
	ara(10);
	
}
