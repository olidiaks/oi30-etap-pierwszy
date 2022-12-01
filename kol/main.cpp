#include <iostream>
#include <deque>

void update_snake();

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// m – długość i szerokość zarazem (plansza jest kwadratem)
// p – liczba przekąsek na planszy
// n – liczba poleceni do obsłużenia
    int m, p, n;
    cin >> m >> p >> n;

// k – kolumna (oś x)
// w – wiersz (oś y)
// c – kolor przekąski
    int wk[m], c[p];
    int *pWK = wk;
    int *pC = c;
    deque<int> snake;
    int snakeColor[n];
    int *pSnakeColor = snakeColor;
    return 0;
}

void update_snake() {
    try {

    }
}
