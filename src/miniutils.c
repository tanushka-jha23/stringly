#include "../headers/miniutils.h"

int digits(int x) {
    int digits = 0;
    while(x > 0) {
        digits++;
        x /= 10;
    }
    return digits;
}
