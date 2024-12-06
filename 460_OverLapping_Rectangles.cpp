#include <bits/stdc++.h>
using namespace std;

typedef struct point {
    int x;
    int y;
} point;

typedef struct rectangle {
    point corner_l;
    point corner_r;
} rec;

int main() {
    rec r1, r2;

    int t; cin >> t;
    while ( t-- ) {
        cin >> r1.corner_l.x >> r1.corner_l.y >> r1.corner_r.x >> r1.corner_r.y;
        cin >> r2.corner_l.x >> r2.corner_l.y >> r2.corner_r.x >> r2.corner_r.y;

        point l, r;
        l.x = max(r1.corner_l.x, r2.corner_l.x);
        l.y = max(r1.corner_l.y, r2.corner_l.y);

        r.x = min(r1.corner_r.x, r2.corner_r.x);
        r.y = min(r1.corner_r.y, r2.corner_r.y);

        if ( l.x >= r.x || l.y >= r.y ) cout << "No Overlap\n";
        else { cout << l.x << " " << l.y << " " << r.x << " " << r.y << endl; }
    }

    return 0;
}
