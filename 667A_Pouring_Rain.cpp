// problem link : https://codeforces.com/contest/667/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {

    int d, h, v, rain_rate;
    cin >> d >> h >> v >> rain_rate;

    const double pi = acos(-1.0);
    double area = pi * pow(d, 2) / 4;

    double drinking_rate = v / area;

    if (drinking_rate < rain_rate) { puts("NO"); }
    else {
        puts("YES");

        double net_rate = drinking_rate - rain_rate;
        double time = h / net_rate;

        cout << time << endl;
    }

    return 0;
}
