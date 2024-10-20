//https://codeforces.com/contest/4/problem/C

#include <iostream>
#include <map>
#include <ctime>

using namespace std;

#define ll long long
const ll N = 2e5+100;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<string, ll> mp;

//    clock_t start_time, end_time;
//    start_time = clock();

    int n;
    cin >> n;

    while ( n-- ) {
        
        string s;
        cin >> s;

        if ( !mp[s] ) {
            cout << "OK" << endl;
            mp[s]++;
        }
        else {
            cout << s << mp[s] << endl;
            mp[s]++;
        }
    }
    
//    end_time = clock();
//    
//    double elapsed_time_ms = double(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
//
//    std::cout << "Elapsed time: " << elapsed_time_ms << " ms" << std::endl;

    return 0;
}
