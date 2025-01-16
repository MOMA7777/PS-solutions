#include <bits/stdc++.h>
using namespace std;
int main() {
//    int n, cnt = 0; 
//    scanf("%d", &n);
//
//    double fn = sqrt(n);
//
//    for(int i = 1; i <= (int)fn; i++) {
//        if (n % i == 0) {
//            if ((n / i) != i) cnt += 2;
//            else            cnt++;
//        }
//    } 
//
//    if (cnt % 2 == 0) cout << "no" << endl;
//    else              cout << "yes"<< endl; 

    int n;
    
    while (cin >> n && n) {
        double r = sqrt(n);

        if (r * r == n) cout << "yes" << endl;
        else            cout << "no"  << endl;
    }

    return 0;
}
