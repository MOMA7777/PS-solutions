//problem link : https://www.google.com/url?sa=t&source=web&rct=j&opi=89978449&url=https://onlinejudge.org/index.php%3Foption%3Dcom_onlinejudge%26Itemid%3D8%26page%3Dshow_problem%26problem%3D1047&ved=2ahUKEwjQqbbGiPqKAxU5IUQIHUSSMHkQFnoECBIQAQ&usg=AOvVaw1A3B-_qQKLK2JncFoCF3zm

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
   
    int l1 = s1.size(), l2 = s2.size();
    vector<int> res(l1 + l2, 0);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            res[i+j] += ((s1[i]-'0') * (s2[j]-'0'));

            res[i+j+1] += res[i+j] / 10;
            res[i+j] %= 10;
        }
    }

    reverse(res.begin(), res.end());
    bool flag = 0;
    for(int i = 0; i < res.size(); i++) {
        if (res[i]) flag = 1;

        if (flag) cout << res[i];
    }

    cout << endl;

    return 0;
}
