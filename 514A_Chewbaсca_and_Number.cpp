#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;

    for(int i = 0; i < x.size(); i++) {
        int d = x[i] - '0';
        
        if (i == 0 && d == 9) continue;
        if (9 - d < d) x[i] = (char)((9-d) + '0');
    }

    cout << x << endl;

    return 0;
}
