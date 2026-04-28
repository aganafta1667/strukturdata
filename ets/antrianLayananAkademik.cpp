#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(string x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "[INFO] Mahasiswa " << x << " mengambil nomor antrian" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }

        Node* temp = front;
        cout << "[PANGGILAN] Sedang melayani mahasiswa: " << temp->data << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Kondisi Antrian: Kosong" << endl;
            return;
        }

        Node* temp = front;
        cout << "Kondisi Antrian: ";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue antrianAkademik;
    string mhs1 = "A";
    string mhs2 = "B";
    string mhs3 = "C";
    string mhs4 = "D";

    cout << "=== SIMULASI ANTRIAN LAYANAN AKADEMIK ===" << endl;
    cout << endl;
    
    antrianAkademik.enqueue(mhs1);
    antrianAkademik.enqueue(mhs2);
    antrianAkademik.enqueue(mhs3);
    cout << endl;

    antrianAkademik.dequeue();
    cout << endl;

    antrianAkademik.enqueue(mhs4);
    cout << endl;

    antrianAkademik.display();
    cout << endl;

    return 0;
}