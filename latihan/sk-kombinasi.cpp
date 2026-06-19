#include <bits/stdc++.h>
using namespace std;
struct Driver {
    string nama;
    int jarak;
    bool operator<(const Driver& d) const { return jarak > d.jarak; }
};

class FoodDeliveryApp {
private:
    unordered_map<string, string> users;           
    list<string> riwayatPesanan;                  
    queue<string> antrianRestoran;                
    priority_queue<Driver> driverTersedia;        
    stack<string> draftPesanan;                    
    
public:
    void login(string user) { users[user] = "authenticated"; }
    
    void tambahKeKeranjang(string menu) { draftPesanan.push(menu); }
    void batalkanKeranjangTerakhir() { if(!draftPesanan.empty()) draftPesanan.pop(); }
    
    void checkoutPesanan() {
        if(!draftPesanan.empty()) {
            string pesanan = draftPesanan.top();
            antrianRestoran.push(pesanan);
            riwayatPesanan.push_back(pesanan);
            cout << "Pesanan " << pesanan << " masuk ke restoran" << endl;
        }
    }
    
    void cariDriver(string namaDriver, int jarakKm) {
        driverTersedia.push({namaDriver, jarakKm});
    }
    
    void tugaskanDriver() {
        if(!driverTersedia.empty()) {
            cout << "Driver " << driverTersedia.top().nama << " sedang mengambil pesanan" << endl;
            driverTersedia.pop();
        }
    }
};

int main() {
    FoodDeliveryApp goFood;
    cout << "SIMULASI FOOD DELIVERY" << endl;
    
    goFood.login("strukdat");

    goFood.tambahKeKeranjang("Ayam Goreng");
    goFood.tambahKeKeranjang("Es Teh Manis");
    goFood.tambahKeKeranjang("Kerupuk Udang");
    
    goFood.batalkanKeranjangTerakhir(); 
    
    goFood.checkoutPesanan();
    
    goFood.cariDriver("Driver Pak Joko", 5);
    goFood.cariDriver("Driver Mas Adi", 2); 
    
    goFood.tugaskanDriver();
    
    return 0;
}