#include <stdio.h>

int main(void) {
    int x,y;
    for (y = 1; y < 10; y ++) {
        for (x = 1; x < 10; x ++) {
            //%4dで桁ぞろえ
            printf("%4d", x*y);
        }
        printf("\n");
    }
}