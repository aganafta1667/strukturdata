#include <bits/stdc++.h>
using namespace std;

class GoogleMaps {
private:
    unordered_map<string, vector<pair<string, int>>> peta;

public:
    void tambahJalan(string asal, string tujuan, int jarak) {
        peta[asal].push_back({tujuan, jarak});
        peta[tujuan].push_back({asal, jarak});
    }

    void cariRuteTerpendek(string mulai, string tujuan) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, int> jarakMIn;
        
        for (auto const& p : peta) jarakMIn[p.first] = 1e9;
        
        pq.push({0, mulai});
        jarakMIn[mulai] = 0;

        while (!pq.empty()) {
            int jarakSaatIni = pq.top().first;
            string nodeSaatIni = pq.top().second;
            pq.pop();

            if (nodeSaatIni == tujuan) {
                cout << "Jarak terpendek ke " << tujuan << " adalah " << jarakSaatIni << " km" << endl;
                return;
            }

            for (auto const& tetangga : peta[nodeSaatIni]) {
                string nodeTetangga = tetangga.first;
                int beratEdge = tetangga.second;

                if (jarakSaatIni + beratEdge < jarakMIn[nodeTetangga]) {
                    jarakMIn[nodeTetangga] = jarakSaatIni + beratEdge;
                    pq.push({jarakMIn[nodeTetangga], nodeTetangga});
                }
            }
        }
    }
};

int main() {
    GoogleMaps maps;
    cout << "SIMULASI GOOGLE MAPS" << endl;
    
    maps.tambahJalan("Kost", "Apotek", 2);
    maps.tambahJalan("Kost", "Rumah Makan", 5);
    maps.tambahJalan("Apotek", "Rumah Makan", 2);
    maps.tambahJalan("Rumah Makan", "Kampus", 3);
    maps.tambahJalan("Apotek", "Kampus", 6);
    
    maps.cariRuteTerpendek("Kost", "Kampus"); 
    return 0;
}