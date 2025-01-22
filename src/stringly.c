#include "../include/stringly.h"

int str_len(char* c) {
    if(c == NULL) {
        return 0;
    }
    return strlen(c);
}

String* string_from(char* c) {
    String* str = malloc(sizeof(String));
    int len = str_len(c);
    str->data = malloc(len);
    memcpy(str->data, c, len);
    str->len = len;

    return str;
}

String* string_new() {
    String* str = malloc(sizeof(String));
    char* c = malloc(sizeof(char));
    str->data = c;
    str->len = 0;

    return str;
}

String* string_with_capacity(int capacity) {
    String* str = malloc(sizeof(String));
    char* c = malloc(capacity);
    str->data = c;
    str->len = capacity;

    return str;
}

void string_destroy(String* s) {
    free(s->data);
    free(s);
}

void string_print(char* c, int n) {
    for(int i=0; i<n; i++) {
        printf("%c", c[i]);
    }
}

int string_length(String* s) {
    return s->len;
}

char* string_value(String* s) {
    return s->data;
}

void string_concat_from_parts(String* s, String* s1, String* s2) {
    memcpy(s->data, s1->data, s1->len);
    memcpy(s->data+s1->len, s2->data, s2->len);
}


String* string_concat(String* s1, String* s2) {
    String* s = string_with_capacity(s1->len + s2->len);
    string_concat_from_parts(s, s1, s2);
    string_destroy(s1);
    string_destroy(s2);

    return s;
}

void string_push_cstr(String* s, char* str, int strlen) {
    char* c = malloc(s->len+strlen);
    memcpy(c, s->data, s->len);
    memcpy(c+s->len, str, strlen);
    free(s->data);
    s->data = c;
    s->len += strlen;
}

StringSlice string_slice(String* s, int start, int stop) {
    StringSlice c;
    c.len = stop-start+1;
    c.ptr = s->data+start;
    return c;
}

int string_split_count(String* s, char* delimiter) {
    int count = 0;
    for(int i=0; i < s->len; i++) {
        if((i==s->len-1 || i==0) && s->data[i] == *delimiter) {
            continue;
        }
        else if(s->data[i] == *delimiter) {
            count++;
        }
    }
    return count+1;
}

void string_split(String* s, char* delimiter, StringSlice* out) {
    int start = 0;
    int i=0;
    int j=0;
    int len = string_split_count(s, delimiter);
    for(i = 0; i < len; i++) {
        for(j = start; j < s->len; j++) {
            if(s->data[j] == *delimiter) {
                break;
            }
        }
        out[i] = string_slice(s, start, j-1);
        start = j+1;
    }
}

void string_join(String* s, char** c, int len, char* v){
    for(int i=0; i < len; i++) {
        string_push_cstr(s, c[i], str_len(c[i]));
        string_push_cstr(s, v, str_len(v));
    }
}

void string_swapcase(String* s) {
    for(int i=0; i < s->len; i++) {
        if(char_is_uppercase(s->data[i])) {
            s->data[i] = char_lowercase(s->data[i]);
        } else if(char_is_lowercase(s->data[i])) {
            s->data[i] = char_uppercase(s->data[i]);
        }
    }
}

int string_is_numeric(String* s) {
    int is_digit = 1;

    for(int i=0; i < s->len; i++){
        int v = (int)s->data[i];
        if(v < 47 || v > 58)  {
            is_digit = 0;
        }
    }
    return is_digit;
}

