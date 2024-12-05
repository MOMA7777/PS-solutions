#include <bits/stdc++.h>
using namespace std;

double dist = 0;
double get_distance(int x1, int y1, int x2, int y2) {
    return sqrt( pow(x2-x1, 2) + pow(y2-y1, 2) );
}

int main() {

    int n, k, x[100], y[100];
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];

        if ( i ) {
            dist += get_distance(x[i-1], y[i-1], x[i], y[i]);
        }
    }
    
    printf("%lf\n", (dist * k) / 50.000);

    return 0;
}
