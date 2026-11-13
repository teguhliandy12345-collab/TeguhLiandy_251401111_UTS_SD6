
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Queue {
    char data[MAX];
    int front;
    int rear;
};

void initQueue(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.rear < q.front;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}
void enqueue(Queue &q, char huruf) {
    if (!isFull(q)) {
        q.rear++;
        q.data[q.rear] = huruf;
    }
}
char dequeue(Queue &q) {
    if (!isEmpty(q)) {
        char huruf = q.data[q.front];
        q.front++;
        return huruf;
    }

    return '\0';
}
bool isVokal(char huruf) {
    huruf = toupper(huruf);

    return huruf == 'A' || huruf == 'I' ||
           huruf == 'U' || huruf == 'E' ||
           huruf == 'O';
}

int main() {
    Queue q;
    string kata;

    initQueue(q);

    cout << "Masukkankali kata: ";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++) {
        enqueue(q, kata[i]);
    }

    cout << "Singkatan: ";

    while (!isEmpty(q)) {
        char huruf = dequeue(q);

        if (!isVokal(huruf)) {
            cout << huruf;
        }
    }

    cout << endl;

    return 0;
}
