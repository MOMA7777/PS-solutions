//problem link : https://codeforces.com/contest/2037/problem/C

#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n; 
        scanf("%d", &n);
    
        if (n <= 4) {
            puts("-1");
            continue;
        }
    
        for(int i = 1; i <= n; i += 2) {
            if (i == 5) continue;
    
            printf("%d ", i);
        }
    
        printf("5 4 ");
    
        for(int i = 2; i <= n; i += 2) {
            if (i == 4) continue;
    
            printf("%d ", i);
        }
    
        puts(" ");
    }
    return 0;
}
