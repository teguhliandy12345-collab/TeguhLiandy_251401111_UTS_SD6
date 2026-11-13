
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* baru;
    Node* bantu;

    stack<int> s;
    queue<int> q;

    int angka;
    cout << "Masukkan 5 angka:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> angka;

        baru = new Node;
        baru->data = angka;
        baru->next = NULL;

        if (head == NULL) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
    }
    bantu = head;

    while (bantu != NULL) {
        if (bantu->data % 3 == 0) {
            s.push(bantu->data);
        } else {
            q.push(bantu->data);
        }

        bantu = bantu->next;
    }
    cout << "Output Stack : ";
while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\nOutput Queue : ";

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    bantu = head;

    while (bantu != NULL) {
        Node* hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    return 0;
}
