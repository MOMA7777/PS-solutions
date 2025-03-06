#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {}
    
    int ping(int t) {
        q.push(t);

        while (!q.empty() && q.front() < (t-3000)) {
            q.pop();
        }

        return q.size();
    }
};


int main() {
    RecentCounter rc;
   
    cout << rc.ping(1) << endl;
    cout << rc.ping(2) << endl;
    cout << rc.ping(3) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3003) << endl;
    cout << rc.ping(5) << endl;

    return 0;
}
