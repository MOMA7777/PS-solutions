#include <stdio.h>
int main() {
    int n; 
    scanf("%d", &n);

    char s[n];
    for (int i = 0; i < n; i++) scanf("%c", &s[i]);

    for (int i = n-1; i >= 0; --i) {
        if (s[i] != '.') {
            if (s[i] == 'L') {
                while ( s[i] == 'L' ) --i;

                if (s[i-1] == 'R') printf("%d %d\n", i+1, i+1);
                else               printf("%d %d\n", i+1, i  );
                break;
            }
            else {
                printf("%d %d\n", i, i+1);
                break;
            }
        }
    }

    return 0;
}
