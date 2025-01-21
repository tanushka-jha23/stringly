#include "../include/stringly.h"

int string_trim(String* s) {
    int i = string_trim_left(s);
    int j = string_trim_right(s);
    return j;
}

int string_is_whitespace(String* s) {
    int i = 0;
    while(s->data[i] == ' ') {
        i++;
    }
    return i == s->len;
}

void string_empty(String* s) {
    memcpy(s->data, "", 0);
    s->len = 0;
}

int string_whitespace_from_left(String* s) {
    int i = 0;
    while(s->data[i] == ' ') {
        i++;
    }
    return i;
}

int string_whitespace_from_right(String* s) {
    int i = s->len - 1;
    while(s->data[i] == ' ') {
        i--;
    }
    return s->len - i - 1;
}

void string_substring(String* s, int a, int b) {
    int j = b - a;
    char* c = malloc(j-1);
    memcpy(c, s->data+a, b);
    free(s->data);
    s->len = j;
    s->data = c;
}

int string_trim_left(String* s) {
    if(string_is_whitespace(s)) {
        string_empty(s);
        return 0;
    }
    int i = string_whitespace_from_left(s);
    string_substring(s, i, s->len);
    return s->len;
}

int string_trim_right(String* s) {
    if(string_is_whitespace(s)) {
        string_empty(s);
        return 0;
    }
    int i = string_whitespace_from_right(s);
    string_substring(s, 0, s->len-i);
    return s->len;
}
