#include <bits/stdc++.h>
using namespace std;

class SpotifyPlaylist {
private:
    list<string> playlist;
    list<string>::iterator current;

public:
    void tambahLagu(string judul) {
        playlist.push_back(judul);
        if (playlist.size() == 1) current = playlist.begin();
    }

    void playCurrent() {
        if (!playlist.empty()) cout << "Memutar: " << *current << endl;
    }

    void next() {
        if (current != prev(playlist.end())) {
            current++;
            playCurrent();
        } 
        else cout << "Anda sudah berada di urutan lagu terakhir" << endl;
    }

    void previous() {
        if (current != playlist.begin()) {
            current--;
            playCurrent();
        } 
        else cout << "Anda sudah berada di urutan lagu awal" << endl;
    }
};

int main() {
    SpotifyPlaylist spotify;
    cout << "SIMULASI PLAYLIST SPOTIFY" << endl;
    spotify.tambahLagu("Balonku ada lima");
    spotify.tambahLagu("Pelangi");
    spotify.tambahLagu("Bintang Kecil");
    
    spotify.playCurrent();
    spotify.next();       
    spotify.next();       
    spotify.previous();   
    return 0;
}