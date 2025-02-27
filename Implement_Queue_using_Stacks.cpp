#include <bits/stdc++.h>
using namespace std;

/*
 
    Stack vs Queue ? 
    ----------------

    1 - Queue :
     q = 1, 2, 3, 4, 5. insert(6).
     q2.push(q.front()) = 1, 2, 3, 4, 5.

     q = 6.
     q1.push(q2.front()) = 6, 1, 2, 3, 4, 5.



     2 - Stack : 
        start reversal .
        so s will be 3, 2, 1 ensuring first will be top().
        by :-
        s is reversal
        1 (2) ==> 2, 1.
        2, 1 (3) ==> 3, 2, 1.
        3, 2, 1 (4) ==> 4, 3, 2, 1.
        
        by taking `temp_stack` as stack take the correct order!
        1 (2) ==> 2, 1 --> tmp = 1.
        2, 1 (3) ==> 3, 2, 1 --> tmp = 1, 2.
        3, 2, 1 (4) ==> 4, 3, 2, 1 --> tmp = 1, 2, 3.

*/










class MyQueue {
public:
    stack<int> s, t;
    MyQueue() {}
    
    void push(int x) {
        while (!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }
    
    int pop() {
        if (s.empty()) return -1;
        int value = s.top();
        s.pop();
        return value;
    }
    
    int peek() {
        if (s.empty()) return -1;
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};









int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl; // 1
    cout << q.pop() << endl;  // 1                          
    cout << q.peek() << endl; // 2
    return 0;
}
