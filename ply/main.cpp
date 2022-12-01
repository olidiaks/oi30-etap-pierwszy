

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, H;
    string w;
    cin >> n >> H;
    cin >> w;

    int changeCounter = 0;
    int deepCounter = 0;

    for (int i = 0; i < n - 1; i++) {
        char bracket = w[i];
        if (bracket == '(') {
            deepCounter++;
        }

        if (bracket == ')') {
            deepCounter--;
        }

        if (deepCounter > H || deepCounter <= 0) {
            changeCounter++;
            if (bracket == ')') {
                deepCounter += 2;
            } else {
                deepCounter -= 2;
            }
        }
    }
    cout << changeCounter;
}
