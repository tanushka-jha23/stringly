#include "../headers/stringly.h"

int char_is_uppercase(char c) {
    return c <= 'Z' && c >= 'A';
}

int char_is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

char char_uppercase(char c) {
    return char_is_lowercase(c) ? c-32 : c;
}

char char_lowercase(char c) {
    return char_is_uppercase(c) ? c+32 : c;
}



