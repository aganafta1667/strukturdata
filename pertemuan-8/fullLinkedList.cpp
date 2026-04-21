#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    //INSERT
    void insert(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted: " << val << endl;
    }
    
    //DELETE
    void deleteNode(int val) {
        if (head == NULL) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted: " << val << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Value " << val << " not found for deletion." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Deleted: " << val << endl;
    }

    //SEARCH
    bool search(int val) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == val) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //UPDATE
    void update(int oldVal, int newVal) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == oldVal) {
                current->data = newVal;
                cout << "Updated: " << oldVal << " -> " << newVal << endl;
                return;
            }
            current = current->next;
        }
        cout << "Value " << oldVal << " not found for updating." << endl;
    }

    //ISI LINKED LIST
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    cout << "PROSES INSERT" << endl;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();

    cout << endl << "PROSES SEARCHING" << endl;
    int searchVal = 20;
    if (list.search(searchVal)) {
        cout << searchVal << " is found in the list." << endl;
    } else {
        cout << searchVal << " is not found." << endl;
    }

    cout << endl << "PROSES UPDATING" << endl;
    list.update(20, 25);
    list.display();

    cout << endl << "PROSES DELETION" << endl;
    list.deleteNode(30);
    list.deleteNode(10);
    list.display();

    return 0;
}