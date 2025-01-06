// problem link : https://codeforces.com/contest/1237/problem/A
// how to appracoh balance in sequence of data ? 
// rounding differ from negatives to positives.

#include <stdio.h>
int main() {

    int n, b, flag = 1;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);

        if (a % 2 == 0) printf("%d\n", a / 2);
        else {
            
            if ( flag ) {
                if (a > 0) b = (a / 2) + 1;
                else       b = (a / 2);
                printf("%d\n", b);

                flag = 0;
            }
            else { 
                
                if (a > 0) b =  a / 2;
                else       b = (a / 2) - 1;
                printf("%d\n", b);

                flag = 1;
            }
        }
    }

    return 0;
}
