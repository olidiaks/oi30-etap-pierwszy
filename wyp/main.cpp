#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //n – liczba ciężarówek
    //D – długość auta bajtazara
    //W – dystans, jaki przejechał bajtazar
    //M – czas, w jaki bajtazarowi zajęła podróż
    //V – Prędkość bajtazara

    int n;
    double D, W, M;
    cin >> n >> D >> W >> M;
    double V = W / M;

    double x[n];
    double *pX = x;
    double *pXEnd = pX + n;

    double d[n];
    double *pD = d;
    double *pDEnd = pD + n;

    double v[n];
    double *pV = v;
    double *pVEnd = pV + n;

    for (int i = 0; i < n; i++) {
        double a, b, c, e;
        cin >> a >> b >> c >> e;
        *(pX + i) = a;
        *(pD + i) = b;
        *(pV + i) = c / e;
    }

    double changeLaneCounter = 0;
    int startIndex = 0;

    double globalTime = 0;
    bool isOnRightLane = true;
    while (n - startIndex > 0) {
        double actionTime;
        bool isActionTimeChanged = false;
        const double bajtazFrontPosition = V * globalTime;
        const double truckFrontPosition = *(pX + startIndex);
        const double truckLength = *(pD + startIndex);
        const double trackSpeed = *(pV + startIndex);
        double distanceBetweenEndTrackAndBajtazarFront = truckFrontPosition - truckLength - bajtazFrontPosition;
        double distanceBetweenTrackFrontAndBajtazarEnd = truckFrontPosition - bajtazFrontPosition - D;
        const double nextTruckFrontPosition = *(pX + startIndex + 1);
        const double nextTruckLength = *(pD + startIndex + 1);
        const double timeNeedBajatzToBeBehindTruck = abs(
                distanceBetweenTrackFrontAndBajtazarEnd / (V - trackSpeed) / 2);
        if (distanceBetweenEndTrackAndBajtazarFront > 0) {
            distanceBetweenEndTrackAndBajtazarFront = 0;
            globalTime += timeNeedBajatzToBeBehindTruck;
            actionTime = timeNeedBajatzToBeBehindTruck;
            isActionTimeChanged = true;
        }
        if (
                round(1000 * distanceBetweenTrackFrontAndBajtazarEnd) / 1000 == 0 &&
                nextTruckFrontPosition - nextTruckLength - truckFrontPosition >= D) {
            isOnRightLane = true;
        }
        if (round(1000 * distanceBetweenEndTrackAndBajtazarFront) / 1000 <= 0) {
            const double timeNeedToBajtazarBeInFrontOfTruck = abs(
                    distanceBetweenEndTrackAndBajtazarFront / (trackSpeed - V) / 2);
            globalTime += timeNeedToBajtazarBeInFrontOfTruck;
            actionTime = timeNeedToBajtazarBeInFrontOfTruck;
            isActionTimeChanged = true;
            distanceBetweenTrackFrontAndBajtazarEnd = 0;
        }
        if (round(1000 * distanceBetweenTrackFrontAndBajtazarEnd) / 1000 == 0) {
            startIndex++;
        }

        if (round(1000 * distanceBetweenEndTrackAndBajtazarFront) / 1000 == 0 && isOnRightLane) {
            changeLaneCounter++;
            isOnRightLane = false;
        }

        if (isActionTimeChanged) {
            *pXEnd = *pXEnd + *pVEnd * actionTime;

            for (int i = n - 2; i >= startIndex; i--) {
                const double speed = *(pV + i);
                const double actualPosition = *(pX + i) + speed * actionTime;
                const double nextEnd = *(pX + i + 1) - *(pD + i + 1);
                const double nextSpeed = *(pV + i + 1);
                if (actualPosition < nextEnd) {
                    *(pX + i) = actualPosition;
                } else {
                    *(pX + i) = nextEnd;
                }
                if (actualPosition >= nextEnd && nextSpeed != speed) {
                    *(pV + i) = nextSpeed;
                }
            }
        }
    }

    cout << changeLaneCounter;

    return 0;
}
