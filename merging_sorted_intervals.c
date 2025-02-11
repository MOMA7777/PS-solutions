#include <stdio.h>

/* don't write two scanf() in one loop */

/*
 *  merging two sorted intervals
 *
 *  a --> interval 1 : i
 *  b --> interval 2 : j
 *  c --> mix        : k
 *  
 *  every interval will compared with the same positoin with the other 
 *  if smaller ? go to next position in same interval
 *
 *  a : 1 3 5 7 9
 *  b : 2 4 6 8 10
 *
 * 1 or 2 ==> 1 : i++
 * 3 or 2 ==> 2 : j++
 * 3 or 4 ==> 3 : i++
 * ...
 *
 * and k++ at every iterate regardless of the result of comparison.
 *
 * */

int a[1000];
int b[1000];
int c[1000];

int k = 0;
void rec (int i, int j) {
    while (i < 5 && j < 5) {
        if (a[i] <= b[j]) {
            c[k] = a[i];
            ++i;
        }
        else {
            c[k] = b[j];
            ++j;
        }
        ++k;
    }

} 

int main() {

    for(int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    } /* C is very problematic language */

    rec(0, 0);

    for(int i = 0; i <= 10; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}
