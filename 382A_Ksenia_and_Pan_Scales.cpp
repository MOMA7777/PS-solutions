#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, extra;
    cin >> s >> extra;

    string l = s.substr(0, s.find('|'));
    string r = s.substr(s.find('|')+1, s.length()); 

    int lw = l.length(), rw = r.length();
    int total = lw + rw + extra.length(), delta = abs(lw - rw);

    if ( total % 2 != 0 || delta > extra.size()) cout << "Impossible" << endl; 
    else {
        int targetLen = total / 2;

        int targetL = targetLen - lw;

        l = l + extra.substr( 0, (total/2) - lw );
        r = r + extra.substr((total/2) - lw, (total/2) - rw); //zero based

        cout << l + '|' + r << endl;
    }


    return 0;
}
