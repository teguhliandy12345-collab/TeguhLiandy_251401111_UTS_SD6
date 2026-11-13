
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    float kehadiran;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;

void insertTail(string nama, float kehadiran) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->kehadiran = kehadiran;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void deleteHead() {
    if (head == NULL) {
        return;
    }

    Mahasiswa* hapus = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }

    delete hapus;
}

void deleteTail() {
    if (head == NULL) {
        return;
    }

    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Mahasiswa* bantu = head;

    while (bantu->next != tail) {
        bantu = bantu->next;
    }

    delete tail;
    tail = bantu;
    tail->next = NULL;
}

void tampilkan() {
    Mahasiswa* bantu = head;
    int nomor = 1;

    cout << "\nList Mahasiswa tidak layak ujian:\n";

    while (bantu != NULL) {
        if (bantu->kehadiran < 80) {
            cout << nomor << " | " << bantu->nama
                 << " (" << bantu->kehadiran
                 << "%) - Tidak layak kau ujian" << endl;
            nomor++;
        }

        bantu = bantu->next;
    }

    if (nomor == 1) {
        cout << "Tidak ada mahasiswa yang tidak layak ujian.\n";
    }
}

int main() {
    int pilih;
    string nama;
    float kehadiran;

    do {
        cout << "\nPilih menu:\n";
        cout << "1. Insert tail\n";
        cout << "2. Delete head\n";
        cout << "3. Delete tail\n";
        cout << "4. Tampilkan Mahasiswa Tidak Layak Ujian\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                cin.ignore();
                cout << "Nama : ";
                getline(cin, nama);

                cout << "Persentase (%) : ";
                cin >> kehadiran;

                insertTail(nama, kehadiran);
                break;

            case 2:
                deleteHead();
                break;

            case 3:
                deleteTail();
                break;

            case 4:
                tampilkan();
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 0);

    while (head != NULL) {
        deleteHead();
    }

    return 0;
}