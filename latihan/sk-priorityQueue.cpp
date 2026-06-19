#include <bits/stdc++.h>
using namespace std;

struct PasienIGD {
    string nama;
    int tingkatPrioritas;

    bool operator<(const PasienIGD& p) const {
        return tingkatPrioritas < p.tingkatPrioritas;
    }
};

class SistemIGD {
private:
    priority_queue<PasienIGD> antrianIGD;

public:
    void masukIGD(string nama, int prioritas) {
        antrianIGD.push({nama, prioritas});
    }

    void layani() {
        if (!antrianIGD.empty()) {
            cout << "Melayani: " << antrianIGD.top().nama << " (Prioritas " << antrianIGD.top().tingkatPrioritas << ")" << endl;
            antrianIGD.pop();
        }
        else cout << "Antrian IGD telah habis" << endl;
    }
};

int main() {
    SistemIGD igd;
    cout << "SIMULASI ANTRIAN IGD" << endl;
    
    igd.masukIGD("Pasien A - Batuk Pilek", 1);
    igd.masukIGD("Pasien B - Serangan Jantung", 3);
    igd.masukIGD("Pasien C - Patah Tulang", 2);
    
    igd.layani();
    igd.layani();

    return 0;
}