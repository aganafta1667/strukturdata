#include <bits/stdc++.h>
using namespace std;

class RankingECommerce {
private:
    priority_queue<pair<int, string>> maxHeap;

public:
    void tambahPenjualan(string produk, int jumlahTerjual) {
        maxHeap.push({jumlahTerjual, produk});
    }

    void tampilkanProdukTerlaris() {
        if (!maxHeap.empty()) {
            cout << "Produk Terlaris: " << maxHeap.top().second << " (Terjual: " << maxHeap.top().first << ")" << endl;
        }
    }
};

int main() {
    RankingECommerce toko;
    cout << "SIMULASI RANKING E-COMMERCE" << endl;
    
    toko.tambahPenjualan("Sepatu Roda", 150);
    toko.tambahPenjualan("Laptop Gaming", 500);
    toko.tambahPenjualan("Kabel Charger", 420);
    
    toko.tampilkanProdukTerlaris(); 
    return 0;
}