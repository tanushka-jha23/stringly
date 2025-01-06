#include "../include/stringly.h"//function to convert any string into struct String

///string constructor from another string
String* string_from(char* c) {
    String* str = malloc(sizeof(String));
    int len = strlen(c);
    str->data = malloc(len);
    memcpy(str->data, c, len);
    str->len = len;

    return str;
}
///empty string constructor
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
///free memory of string
void string_destroy(String* s) {
    free(s->data);
    free(s);
}

///function to print the value of string
void string_print(char* c) {
    String* s = string_from(c);
    for(int i=0; i<s->len; i++) {
        printf("%c", s->data[i]);
    }
}

///function that returns length of a string
int string_length(String* s) {
    return s->len;
}

///function that returns value of a string
char* string_value(String* s) {
    return s->data;
}

///function that takes two strings and returns their concatenated string
String* string_concat(String* s1, String* s2) {
    String* s = string_with_capacity(s1->len + s2->len);
    int i = 0;
    memcpy(s->data, s1->data, s1->len);
    memcpy(s->data+s1->len, s2->data, s2->len);

    return s;
}

///trims the trailing spaces from beginning and end of string
int string_trim(String* s) {
    int i = 0;
    while(s->data[i] == ' ') {
        i++;
    }
    int j = s->len - 1;
    while(s->data[j] == ' ') {
        j--;
    }
    char* c = malloc(j-i+1);
    memcpy(c, s->data+i, j-i+1);
    free(s->data);
    s->len = j-i+1;
    s->data = c;

    return j-i+1;
}

///function to trim all the trailing spaces from beginning of string
int string_trim_left(String* s) {
    int i = 0;
    while(s->data[i] == ' ') {
        i++;
    }
    char* c = malloc(s->len-i);
    memcpy(c, s->data+i, s->len);
    free(s->data);
    s->len = s->len-i;
    s->data = c;

    return s->len;
}

///function to trim all the trailing spaces from the end of string
int string_trim_right(String* s) {
    int i = s->len - 1;
    while(s->data[i] == ' ') {
        i--;
    }
    char* c = malloc(i+1);
    memcpy(c, s->data, i+1);
    free(s->data);
    s->len = i+1;
    s->data = c;

    return s->len;
}

















