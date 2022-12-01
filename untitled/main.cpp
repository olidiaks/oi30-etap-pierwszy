#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    // n – Długości listy Bajtka, tego bardziej doświadczonego.
    // m – Długość listy Bitka, tego mniej doświadczonego.
    // k – Ilość typów wagonów.
    cin >> n >> m >> k;
    bool isProbablyWrittenByBitek[n];
    bool *pIsProbablyWrittenByBitek = isProbablyWrittenByBitek;

    int bajtekCarriage[n];
    int *pBajtekCarriage = bajtekCarriage;
    for (int i = 0; i < n; i++) {
        cin >> *(pBajtekCarriage + i);
        *(pIsProbablyWrittenByBitek + i) = false;
    }

    int bitekCarriage[m];
    int *pBitekCarriage = bitekCarriage;
    for (int i = 0; i < m; i++) {
        cin >> *(pBitekCarriage + i);
    }

//    for (int i = 0, j = 0; i < n; i++) {
//        int wba = *(pBajtekCarriage + i);
//        int wbi = *(pBitekCarriage + j);
//        if (*(pBajtekCarriage + i) == *(pBitekCarriage + j)){
//            cout << 1 << " ";
//            j++;
//        } else cout << 0 << " ";
//    }


    if (k != 1) {
        for (int i = 0, j = 0; i < n && j < m; i++) {
            int wba = *(pBajtekCarriage + i);
            int wbi = *(pBitekCarriage + j);
            if (*(pBajtekCarriage + i) == *(pBitekCarriage + j)) {
                *(pIsProbablyWrittenByBitek + i) = true;
                j++;
            }
        }

        for (int i = n - 1, j = m - 1; i >= 0 && j > 0; i--) {
            if (*(pBajtekCarriage + i) == *(pBitekCarriage + j)) {
                *(pIsProbablyWrittenByBitek + i) = true;
                j--;
            }
        }

//    for (int i = 0; i < m; i++) {
//        for (int j = i; j < n; j++) {
//            if (*(pBitekCarriage + i) == *(pBajtekCarriage + j)) {
//                *(pIsProbablyWrittenByBitek + i) = true;
//                break;
//            };
//        }
//    }

        for (int i = 0; i < n; i++) {
            cout << *(pIsProbablyWrittenByBitek + i) << " ";
        }

    } else {
        for (int i = 0; i < n; ++i) {
            cout << 1 << " ";
        }
    }


    return 0;
}
