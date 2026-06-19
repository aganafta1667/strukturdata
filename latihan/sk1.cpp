#include <bits/stdc++.h>
using namespace std;

struct Mahasiswa {
    string nrp;
    string password;
    string nama;
    int tingkatPrioritas; 
};

struct PrioritasLayanan {
    string nama;
    int tingkatPrioritas;   
    bool operator<(const PrioritasLayanan& other) const {
        return tingkatPrioritas < other.tingkatPrioritas; 
    }
};

struct TreeNode {
    string namaOrganisasi;
    vector<TreeNode*> divisiBawahan;
    
    TreeNode(string nama) : namaOrganisasi(nama) {}
};

class SmartCampusSystem {
private:
    unordered_map<string, Mahasiswa> databaseMahasiswa;
    list<string> riwayatAktivitas;
    queue<string> antrianKonsultasi;
    TreeNode* rootOrganisasi;
    unordered_map<string, vector<pair<string, int>>> petaKampus;
    stack<string> krsStack;
    priority_queue<PrioritasLayanan> layananPrioritas;
    string currentUser = "";

public:
    SmartCampusSystem() {
        rootOrganisasi = new TreeNode("Rektor");
    }

    void registrasi(string nrp, string pass, string nama, int prioritas) {
        databaseMahasiswa[nrp] = {nrp, pass, nama, prioritas};
        cout << "Berhasil mendaftar: " << nama << endl;
    }

    bool login(string nrp, string pass) {
        if (databaseMahasiswa.find(nrp) != databaseMahasiswa.end()) {
            if (databaseMahasiswa[nrp].password == pass) {
                currentUser = databaseMahasiswa[nrp].nama;
                tambahRiwayat("Login ke sistem");
                cout << "Login berhasil. Selamat datang, " << currentUser << "!" << endl;
                return true;
            }
        }
        cout << "Login gagal. NRP atau Password salah." << endl;
        return false;
    }

    void tambahRiwayat(string aktivitas) {
        if (currentUser != "") {
            riwayatAktivitas.push_back(currentUser + " - " + aktivitas);
        }
    }

    void tampilkanRiwayat() {
        cout << endl;
        cout << "RIWAYAT AKTIVITAS" << endl;
        for (const string& aktivitas : riwayatAktivitas) {
            cout << "-> " << aktivitas << endl;
        }
    }

    void ambilAntrianKonsultasi() {
        if (currentUser == "") return;
        antrianKonsultasi.push(currentUser);
        tambahRiwayat("Mengambil antrian konsultasi");
        cout << currentUser << " masuk ke antrian konsultasi reguler" << endl;
    }

    void panggilAntrianBerikutnya() {
        if (!antrianKonsultasi.empty()) {
            cout << "Memanggil untuk konsultasi: " << antrianKonsultasi.front() << endl;
            antrianKonsultasi.pop();
        } else {
            cout << "Antrian konsultasi kosong" << endl;
        }
    }

    void setupOrganisasiDummy() {
        TreeNode* wr1 = new TreeNode("Wakil Rektor Akademik");
        TreeNode* ft = new TreeNode("Fakultas Teknik");
        TreeNode* fe = new TreeNode("Fakultas Ekonomi");
        
        wr1->divisiBawahan.push_back(ft);
        wr1->divisiBawahan.push_back(fe);
        rootOrganisasi->divisiBawahan.push_back(wr1);
    }

    void cetakOrganisasi(TreeNode* node, string prefix = "") {
        if (node == nullptr) return;
        cout << prefix << "- " << node->namaOrganisasi << endl;
        for (TreeNode* anak : node->divisiBawahan) {
            cetakOrganisasi(anak, prefix + "  ");
        }
    }
    
    void tampilkanOrganisasi() {
        cout << endl;
        cout << "STRUKTUR ORGANISASI KAMPUS" << endl;
        cetakOrganisasi(rootOrganisasi);
    }

    void tambahJalan(string dari, string ke, int jarak) {
        petaKampus[dari].push_back(make_pair(ke, jarak));
        petaKampus[ke].push_back(make_pair(dari, jarak));
    }

    void tampilkanPeta() {
        cout << endl;
        cout << "PETA KAMPUS" << endl;
        for (auto const& pair : petaKampus) {
            cout << pair.first << " terhubung ke: ";
            for (auto const& tetangga : pair.second) {
                cout << "[" << tetangga.first << " (" << tetangga.second << "m)] ";
            }
            cout << endl;
        }
    }

    void tambahMatkulKRS(string kodeMatkul) {
        krsStack.push(kodeMatkul);
        tambahRiwayat("Menambahkan Matkul: ");
        cout << "Mata kuliah " << kodeMatkul << " ditambahkan ke KRS" << endl;
    }

    void undoKRS() {
        if (!krsStack.empty()) {
            string matkulDihapus = krsStack.top();
            krsStack.pop();
            tambahRiwayat("Membatalkan (Undo) Matkul: " + matkulDihapus);
            cout << "DIBATALKAN: Mata kuliah " << matkulDihapus << " dihapus dari KRS" << endl;
        } else cout << "Tidak ada operasi KRS yang bisa di-undo" << endl;
    }

    void masukLayananPrioritas(string nrp) {
        if (databaseMahasiswa.find(nrp) != databaseMahasiswa.end()) {
            Mahasiswa mhs = databaseMahasiswa[nrp];
            layananPrioritas.push({mhs.nama, mhs.tingkatPrioritas});
            cout << mhs.nama << " (Level Prioritas: " << mhs.tingkatPrioritas << ") masuk layanan khusus" << endl;
        }
    }

    void layaniPrioritasBerikutnya() {
        if (!layananPrioritas.empty()) {
            PrioritasLayanan dilayani = layananPrioritas.top();
            layananPrioritas.pop();
            cout << "Melayani jalur prioritas: " << dilayani.nama << " (Prioritas " << dilayani.tingkatPrioritas << ")\n";
        } else cout << "Antrian layanan prioritas kosong." << endl;
    }
};

int main() {
    SmartCampusSystem kampus;
    
    kampus.registrasi("5025251001", "pass123", "Andi (Mahasiswa Reguler)", 1);
    kampus.registrasi("5025251002", "pass456", "Budi (Mahasiswa Tingkat Akhir)", 2);
    kampus.registrasi("5025251003", "pass789", "Citra (Mahasiswa Difabel)", 3);

    kampus.setupOrganisasiDummy();

    kampus.tambahJalan("Gerbang Utama", "Fakultas Teknik", 200);
    kampus.tambahJalan("Gerbang Utama", "Perpustakaan", 400);
    kampus.tambahJalan("Fakultas Teknik", "Perpustakaan", 150);

    cout << endl;
    cout << "LOGIN KE SISTEM" << endl;
    kampus.login("5025251001", "pass123");

    cout << endl;
    cout << "PENGISIAN KRS" << endl;
    kampus.tambahMatkulKRS("IF101");
    kampus.tambahMatkulKRS("IF102");
    kampus.undoKRS();

    cout << endl;
    cout << "ANTRIAN REGULER" << endl;
    kampus.ambilAntrianKonsultasi();
    kampus.panggilAntrianBerikutnya();

    cout << endl;
    cout << "ANTRIAN PRIORITAS" << endl;
    kampus.masukLayananPrioritas("5025251001"); 
    kampus.masukLayananPrioritas("5025251003"); 
    kampus.masukLayananPrioritas("5025251002");
    
    kampus.layaniPrioritasBerikutnya();
    kampus.layaniPrioritasBerikutnya();

    kampus.tampilkanPeta();
    kampus.tampilkanOrganisasi();

    kampus.tampilkanRiwayat();

    return 0;
}