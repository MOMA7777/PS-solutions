//problem link : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1552

#include <stdio.h>

int N = 0;
int biggest_smaller(int a[], int luchu) {
    int l = 0, r = N - 1, res = -1;

    while( l <= r ) {
        int m = (r + l) >> 1;

        if (a[m] < luchu) { res = a[m], l = m + 1; }
        else r = m - 1;
    }

    return res;
}

int lowest_bigger(int a[], int luchu) {
    
    int l = 0, r = N - 1, res = -1;

    while( l <= r ) {
        int m = (r + l) >> 1;

        if (a[m] > luchu) { res = a[m], r = m - 1; }
        else l = m + 1;
    }

    return res;
}

int main() {
    scanf("%d", &N);

    int chimp[N];
    for(int i = 0; i < N; i++) scanf("%d", &chimp[i]);

    int q;
    scanf("%d", &q);

    while (q--) {
        int h;
        scanf("%d", &h);

        int f = biggest_smaller (chimp, h);
        int s = lowest_bigger   (chimp, h);
        
        if (f == -1) printf("X ");
        else printf("%d ", f);
        
        if (s == -1) printf("X");
        else printf("%d", s);
        
        printf("\n");
    }

    return 0;
}
