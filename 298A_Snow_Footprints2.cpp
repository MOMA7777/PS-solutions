#include <bits/stdc++.h>
using namespace std;

#define l 'L'
#define r 'R'

int main() {
    int n;
    cin >> n;
    vector<char> s(n+1);

    for (int i = 1; i <= n; i++) 
        cin >> s[i];

    int i = 2, j = n-1;
    while (s[i] == '.' || s[j] == '.') {
        if (s[i] == '.') i++;
        if (s[j] == '.') j--;
    }

    int mid = (i + j) / 2;

    char cur = s[mid], opp;
    opp = (cur == 'L') ? 'R' : 'L';

    i = mid;
    while (1) {
        if ( s[i] == '.' ) break;
        else if ( s[i] == opp ) {
            if (opp == 'L') { i-=1; break;}
            else            { i+=1; break;}
        }

        (cur == l) ? --i : ++i;
    }

    cout << mid << " " << i << endl; 
}
