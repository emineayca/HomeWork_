#include <iostream>
#include <string>

using namespace std;

// Ýþçi yapýsý
struct Isci {
    string adi;
    string soyadi;
    int yas;
    double aylikucret;
};

// Ýþçi bilgilerini alan fonksiyon
Isci isciBilgileriAl() {
    Isci yeniIsci;

    cout << "Isci adi: ";
    getline(cin, yeniIsci.adi);

    cout << "Isci soyadi: ";
    getline(cin, yeniIsci.soyadi);

    cout << "Isci yasi: ";
    cin >> yeniIsci.yas;

    cout << "Aylik ucret: ";
    cin >> yeniIsci.aylikucret;

    return yeniIsci;
}

int main() {
   
    Isci isciBilgileri = isciBilgileriAl();


    cout << "Isci Adi: " << isciBilgileri.adi << endl;
    cout << "Isci Soyadi: " << isciBilgileri.soyadi << endl;
    cout << "Isci Yasi: " << isciBilgileri.yas << endl;
    cout << "Aylik Ucret: " << isciBilgileri.aylikucret << endl;

    return 0;
}

