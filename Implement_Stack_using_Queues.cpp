#include <bits/stdc++.h>
using namespace std;


/*
    
    1- Using two Queues: 
    --------------------
        One essential queue and Other for Retreival elements.
        
        1 empty essentail one, full retreival.
        2 push (the new element) to essentail.
        3 empty retreival, full essential again.
    
            push(6)
            q1 : 1, 2, 3, 4, 5.
            q2 : __ 
            -------------------
            1 and 2
            q1 : __
            q1 : 6
            q2 : 1, 2, 3, 4, 5.
            -------------------
            3
            q1 : 6, 1, 2, 3, 4, 5.
            q2 : __




    2- One Queue:
    -------------
        1 take queue size before everything.
        2 push (the new element).
        3 for `size` iteration push(queue.front()) and pop(that element).

        push(6)
        q : 1, 2, 3, 4, 5.
        ------------------
        1
        q : 1, 2, 3, 4, 5       size = 5.
        ---------------------------------
        2
        q : 1, 2, 3, 4, 5, 6  
        ---------------------
        3
        q : 6, 1, 2, 3, 4, 5. 

        push(1) push(2) push(3) ...
        pop(1)  pop(2)  pop(3)  ...
        ---------------------
 * */



class MyStack {
    public:
        queue<int> q;
        MyStack() {}
        
        void push(int x) {
            int size = q.size();
            q.push(x);

            while (size--) {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            if (q.empty()) return -1;

            int val = q.front();
            q.pop();
            return val;
        }
        
        int top() {
            if (q.empty()) return -1;
            
            int val = q.front();
            return val;
        }
        
        bool empty() {
            return q.empty();
        }
};





class MyStack {
    public:
        queue<int> q1, q2;
        MyStack() {}
        
        void push(int x) {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);

            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        
        int pop() {
            if (q1.empty()) return -1;

            int val = q1.front();
            q1.pop();
            return val;
        }
        
        int top() {
            int val = q1.front();
            return val;
        }
        
        bool empty() {
            return q1.empty();
        }
};




int main() {
    MyStack stck;

    stck.push(1);
    stck.push(2);
    stck.push(3);
    

    cout << stck.top() << endl;
    cout << stck.pop() << endl;
    cout << stck.top() << endl;


    return 0;
}
