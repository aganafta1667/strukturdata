#include <bits/stdc++.h>
using namespace std;

class RumahSakit {
private:
    queue<string> antrian;

public:
    void tambahPasien(string nama) {
        antrian.push(nama);
        cout << nama << " masuk antrian" << endl;
    }

    void panggilPasien() {
        if (!antrian.empty()) {
            cout << "Melayani pasien: " << antrian.front() << endl;
            antrian.pop();
        } 
        else cout << "Tidak ada antrian" << endl;
    }
};

int main() {
    RumahSakit rs;
    cout << "SIMULASI ANTRIAN RS" << endl;
    rs.tambahPasien("Andi");
    rs.tambahPasien("Budi");
    rs.tambahPasien("Citra");
    
    rs.panggilPasien(); 
    rs.panggilPasien(); 
    return 0;
}