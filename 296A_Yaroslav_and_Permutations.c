#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
    int a[n+1], freq[100000+1] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
        freq[a[i]]++;
    }

    int mx_freq = -1, sum_other_freq = 0;
    for (int i = 0; i <= 100000; i++) {
        if (freq[i] > mx_freq) mx_freq = freq[i];
    }

    sum_other_freq = n - mx_freq;

    if (sum_other_freq >= mx_freq - 1) puts("YES");
    else                               puts("NO");
}
