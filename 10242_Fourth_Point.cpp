// problem link : https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1183 

#include <bits/stdc++.h>
using namespace std;

typedef struct side {
    double x1;
    double y1;
    double x2;
    double y2;
} side;

int main() {

    side s, m;
    cin >> s.x1 >> s.y1 >> s.x2 >> s.y2 >> m.x1 >> m.y1 >> m.x2 >> m.y2;

    double dist1_x = -(s.x2 - s.x1);
    double dist1_y = -(s.y2 - s.y1);

    double fourth_x, fourth_y;
    fourth_x = m.x2 + dist1_x;
    fourth_y = m.y2 + dist1_y;


    printf("%.3lf %.3lf\n", fourth_x, fourth_y);


    return 0;
}
