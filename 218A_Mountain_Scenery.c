//problem link : https://codeforces.com/contest/218/problem/A

#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int y[2*n + 1 + 1];
    for(int i = 1; i <= 2*n+1; i++)
        scanf("%d", &y[i]);

    for(int i = 1; i <= 2*n; i++) {
        if (i % 2 == 0 && k) {
            if ( (y[i]-1 > y[i-1]) && (y[i]-1 > y[i+1]) ) y[i] -= 1, --k;
        }
    }
   
    for(int i = 1; i <= 2*n+1; i++) 
        printf("%d ", y[i]);

    puts(" ");

    return 0;
}
