
#include <iostream>
using namespace std;

int main() {
    int angka[2][3][4];
    int hasil[3][4];


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            angka[0][i][j] = 6 * (i * 4 + j + 1);
            angka[1][i][j] = 3 * (i * 4 + j + 1);

            hasil[i][j] = angka[0][i][j] + angka[1][i][j];
        }
    }

    cout << "Hasil dari Layer 1 dan 2:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
