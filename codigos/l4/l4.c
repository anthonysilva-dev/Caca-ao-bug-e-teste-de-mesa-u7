#include <stdio.h>

union bytes {
    int i;
    unsigned char b[4];
};

int main(void) {
    union bytes u;
    u.i = 0x01020304;

    for (int k = 0; k < 4; k++) {
        printf("%02X ", u.b[k]);
    }
    printf("\n");

    return 0;
}
