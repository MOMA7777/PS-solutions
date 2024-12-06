#include <stdio.h>
int main() {

    int t;
    scanf("%d", &t);

    while (t--) {
        int angle;
        scanf("%d", &angle);
        
        int Exterior = 180 - angle;

        if ( 360 % Exterior == 0 ) puts("YES");
        else puts("NO");
    }

    return 0;
}
